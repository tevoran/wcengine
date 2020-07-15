#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "wce/wce.h"
#include "simulation/sim.h"

long seed=12345678;

int main()
{
    if(sim_init()!=0)
    {
        printf("Couldn't initialise the simulation\n");
    }
    
    printf("seed=%li\n",seed);
    int i=100;
    while(i>0)
    {
        wce_create_planet(seed+i);
        i--;
    }
    SDL_Delay(3000);

    
    SDL_Quit();
    return 0;
}