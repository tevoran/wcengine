#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "wce/wce.h"
#include "simulation/sim.h"

int main()
{
    if(sim_init()!=0)
    {
        printf("Couldn't initialise the simulation");
    }
    
  
    SDL_Delay(3000);

    
    SDL_Quit();
    return 0;
}