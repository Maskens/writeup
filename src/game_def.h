#include "SDL2/SDL_stdinc.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#ifndef GAME_DEF_H
#define GAME_DEF_H

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
  TTF_Font* font;
	int up;
	int down;
	int left;
	int right;
  SDL_bool running;
} App;

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#endif
