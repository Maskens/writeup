#include "input.h"

void doKeyDown(App *app, SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			app->up = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			app->down = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			app->left = 1;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			app->right = 1;
		}
	}
}

void doKeyUp(App *app, SDL_KeyboardEvent *event)
{
	if (event->repeat == 0)
	{
		if (event->keysym.scancode == SDL_SCANCODE_UP)
		{
			app->up = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_DOWN)
		{
			app->down = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_LEFT)
		{
			app->left = 0;
		}

		if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
		{
			app->right = 0;
		}
	}
}


void doInput(App *app) {
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:
				exit(0);
				break;

			case SDL_KEYDOWN:
        if (event.key.keysym.sym == 'q') {
          app->running = SDL_FALSE;
        }

				doKeyDown(app, &event.key);
				break;

			case SDL_KEYUP:
				doKeyUp(app, &event.key);
				break;

			default:
				break;
		}
	}
}
