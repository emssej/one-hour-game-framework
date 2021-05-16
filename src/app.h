#pragma once

typedef enum
State
  {
	 STATE_RUNNING,
	 STATE_QUIT
  } State;

typedef struct
App
{
  State state;

  unsigned short window_width, window_height;
  unsigned short current_time;
  long double delta_time;
} App;

void App_initialize (App *app, unsigned short width,
							unsigned short height);
