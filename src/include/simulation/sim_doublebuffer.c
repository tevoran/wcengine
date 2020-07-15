#include "sim.h"

#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>

extern SDL_Window *window;

void sim_swap_buffer()
{
    SDL_GL_SwapWindow(window); //SDL_Window window is declared in sim.h
}