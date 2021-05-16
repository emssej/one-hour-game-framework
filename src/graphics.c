#include "graphics.h"

void
Graphics_initialize (Graphics *gfx, App *app)
{
  gfx->window = SDL_CreateWindow ("Game", SDL_WINDOWPOS_UNDEFINED,
											 SDL_WINDOWPOS_UNDEFINED, app->window_width,
											 app->window_height, SDL_WINDOW_RESIZABLE
											 | SDL_WINDOW_ALLOW_HIGHDPI);

  if (!gfx->window)
	 {
		FATAL ("Could not initialize SDL window: %s", SDL_GetError ());
	 }
  
  gfx->renderer = SDL_CreateRenderer (gfx->window, -1,
												  SDL_RENDERER_ACCELERATED);

  if (!gfx->window)
	 {
		FATAL ("Could not initialize SDL renderer: %s", SDL_GetError ());
	 }
}

void
Graphics_update (Graphics *gfx, App *app)
{
  SDL_RenderClear (gfx->renderer);

  (void) app;
  
  SDL_RenderPresent(gfx->renderer);
}
