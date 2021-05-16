#include "callbacks.h"
#include "graphics.h"

void
callback_quit (CallbackArgs *args)
{
  if (args->event->type == SDL_QUIT)
	 {
		args->app->state = STATE_QUIT;
	 }
}

void
callback_quit_key (CallbackArgs *args)
{
  if (args->event->type == SDL_KEYDOWN
		&& args->event->key.keysym.sym == SDLK_ESCAPE)
	 {
		args->app->state = STATE_QUIT;
	 }
}

int
main ()
{
  SDL_Init (SDL_INIT_VIDEO);

  App app = { 0 };
  App_initialize (&app, 640, 480);
  
  Graphics gfx = { 0 };
  Graphics_initialize (&gfx, &app);

  Callbacks cbs = { 0 };
  Callbacks_add (&cbs, callback_quit);
  Callbacks_add (&cbs, callback_quit_key);
  
  SDL_Event e;
  
  while (app.state != STATE_QUIT)
	 {
		while (SDL_PollEvent (&e))
		  {
			 Callbacks_handle (&cbs, &(CallbackArgs) { &e, &app });
		  }

		Graphics_update (&gfx, &app);
	 }

  SDL_Quit ();
  
  return 0;
}
