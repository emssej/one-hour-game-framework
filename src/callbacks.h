#pragma once

#include <SDL2/SDL.h>

#include "app.h"
#include "utilities.h"

typedef struct
CallbackArgs
{
  SDL_Event *event;
  App *app;
} CallbackArgs;

typedef void (*Callback) (CallbackArgs *args);

typedef struct
Callbacks
{
  size_t callbacks_size;
  Callback *callbacks;
} Callbacks;

void Callbacks_add (Callbacks *cbs, Callback cb);
void Callbacks_handle (Callbacks *cbs, CallbackArgs *args);
