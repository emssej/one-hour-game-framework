#pragma once

#include <SDL2/SDL.h>

#include "app.h"
#include "utilities.h"

typedef struct
Graphics
{
  SDL_Window *window;
  SDL_Renderer *renderer;
} Graphics;

void Graphics_initialize (Graphics *gfx, App *app);
void Graphics_update (Graphics *gfx, App *app);
