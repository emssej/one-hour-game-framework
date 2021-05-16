#include "graphics.h"

int
main ()
{
  SDL_Init (SDL_INIT_VIDEO);

  App app = { 0 };
  App_initialize (&app, 640, 480);
  
  Graphics gfx = { 0 };
  Graphics_initialize (&gfx, &app);

  SDL_Event e;
  
  while (app.state != STATE_QUIT)
	 {
		while (SDL_PollEvent (&e))
		  {
			 if (e.type == SDL_QUIT)
				{
				  app.state = STATE_QUIT;
				}
		  }

		Graphics_update (&gfx, &app);
	 }

  SDL_Quit ();
  
  return 0;
}
