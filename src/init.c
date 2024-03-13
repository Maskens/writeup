#include "init.h"

SDL_bool init_SDL(App *app) {
  SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1");

  if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
    printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
    return SDL_FALSE;
  } 

  //Create window
  app->window = SDL_CreateWindow(
    "SDL Tutorial",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    SDL_WINDOW_SHOWN 
  );

  if(!app->window) {
    printf("Window! could not be created! SDL_Error: %s\n", SDL_GetError());
    return SDL_FALSE;
  }


  app->renderer = SDL_CreateRenderer(app->window, -1, 
                                     SDL_RENDERER_ACCELERATED);

  if(!app->renderer) {
    printf("Error creating renderer, SDL_Error: %s\n", SDL_GetError());
    return SDL_FALSE;
  }

  // Load font
	app->font = TTF_OpenFont("typewriter.TTF", 72);
	if (!app->font) {
    printf("Error loading font, SDL_Error: %s\n", TTF_GetError());
		return SDL_FALSE;
	}

  return SDL_TRUE;
}
