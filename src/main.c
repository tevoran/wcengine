#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>
#include "wce/wce.h"
#include "simulation/sim.h"

long seed=5;//max 8 digits

int main()
{
    if(sim_init()!=0)
    {
        printf("Couldn't initialise the simulation\n");
    }
    
    printf("seed=%li\n",seed);
    
    //creating pseudorandomly the planet and its host star
    struct planet world=wce_create_planet(seed);
    
    //starting wce_time
    wce_time_start();
    wce_time_get();
    wce_time_set(200);
    wce_set_speed(100);
    SDL_Delay(3000);
    wce_time_get();

    
    SDL_Quit();
    return 0;
}