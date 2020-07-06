#ifndef SIM_H

#define SIM_H

#include <SDL2/SDL.h>

//variables
SDL_Window *window;
SDL_Event event;
SDL_GLContext context;


//functions
int sim_init(); //the initialising function that tries to start everything properly


#endif