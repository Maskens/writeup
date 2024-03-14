#include <stdio.h>
#include "src/game_def.h"
#include "src/init.h"
#include "src/input.h"

void readFile(char words[][10]);

int main() {
  App app;
  char words[1000][10];
  readFile(words);

  TTF_Init();

  if(!init_SDL(&app)) {
    printf("Could not init SDL");
  }

  app.running = SDL_TRUE;

  //Hack to get window to stay up
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

void readFile(char words[][10]) {
  FILE *fPtr;
  fPtr = fopen("assets/words.txt", "r");

  int wordIndex = 0;
  while(fgets(words[wordIndex], 255, fPtr) != NULL) {
    wordIndex++;
  }

  for(int i = 0; i < 1000; i++) {
    printf("%s", words[i]);
  }

  fclose(fPtr);
}

