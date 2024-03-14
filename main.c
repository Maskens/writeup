#include <stdio.h>
#include "src/game_def.h"
#include "src/init.h"
#include "src/input.h"
#include "src/file.h"

int main() {
  App app;
  char words[1000][10];
  readFile(words);

  if(!init_SDL(&app)) {
    printf("Could not init SDL");
  }

  app.running = SDL_TRUE;

  SDL_Event event; 

  SDL_Color foreground = {255, 255, 255};

  SDL_Rect dest;
  SDL_Surface *text_surf = TTF_RenderText_Solid(app.font, "Hej", foreground);
  SDL_Texture *text = SDL_CreateTextureFromSurface(app.renderer, text_surf);

  float deltaTime = 0;
  Uint32 lastTime = 0;
  float x = 0;

  while(app.running) { 
    Uint32 time = SDL_GetTicks();
    deltaTime = time - lastTime;
    lastTime = time;

    doInput(&app);

    if (app.left) {
      x -= 1.0 * deltaTime;
    }

    if (app.right) {
      x += 1.0 * deltaTime;
    }

    SDL_RenderClear(app.renderer);

		dest.x = x;
    dest.y = 240;
		dest.w = text_surf->w;
		dest.h = text_surf->h;
		SDL_RenderCopy(app.renderer, text, NULL, &dest);
    SDL_RenderPresent(app.renderer);

    SDL_Delay(16);
  }

  SDL_DestroyTexture(text);
  SDL_FreeSurface(text_surf);

  TTF_CloseFont(app.font);
  SDL_DestroyRenderer(app.renderer);
  SDL_DestroyWindow(app.window);

  return 0;
}

