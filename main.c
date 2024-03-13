#include <stdio.h>
#include "src/game_def.h"
#include "src/init.h"

void doInput();

App app;

int main() {
  TTF_Init();

  if(!init_SDL(&app)) {
    printf("Could not init SDL");
  }

  //Hack to get window to stay up
  SDL_Event event; 
  int running = 1;

  SDL_Color foreground = {255, 255, 255};

  SDL_Rect dest;
  SDL_Surface *text_surf = TTF_RenderText_Solid(app.font, "Hej", foreground);
  SDL_Texture *text = SDL_CreateTextureFromSurface(app.renderer, text_surf);

  float deltaTime = 0;
  Uint32 lastTime = 0;
  float x = 0;

  while(running) { 
    Uint32 time = SDL_GetTicks();
    deltaTime = time - lastTime;
    lastTime = time;

    doInput();

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

void doKeyDown(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			app.up = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			app.down = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			app.left = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			app.right = 1;
		}
	}
}

void doKeyUp(SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			app.up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			app.down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			app.left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			app.right = 0;
		}
	}
}


void doInput(void) {
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
				doKeyDown(&event.key);
				break;

			case SDL_KEYUP:
				doKeyUp(&event.key);
				break;

			default:
				break;
		}
	}
}
