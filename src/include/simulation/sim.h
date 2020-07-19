#ifndef SIM_H
#define SIM_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

//variables
SDL_Window *window;
SDL_Event event;
SDL_GLContext context;


//functions
int sim_init(); //the initialising function that tries to start everything properly
void sim_swap_buffer(); //swapping buffers to display what has been drawn


//loading shader
int sim_load_gl_shaders();

#endif