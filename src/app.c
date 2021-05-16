#include "app.h"

void
App_initialize (App *app, unsigned short width,
					 unsigned short height)
{
  app->window_width = width;
  app->window_height = height;

  app->state = STATE_RUNNING;
}
