#include "wce.h"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <inttypes.h>

uint64_t wce_time=0;
float wce_speed=1;
uint64_t wce_time_SDL=0;
uint64_t wce_time_SDL_old=0;

void wce_time_start()
{
    wce_time_SDL_old=(uint64_t)SDL_GetTicks()/1000;
    //printf("WCE Time SDL: %lu\n",wce_time_SDL);
}

uint64_t wce_time_get() //get the current time in s
{
    wce_time_SDL=(uint64_t)SDL_GetTicks()/1000;
    wce_time=((wce_time_SDL-wce_time_SDL_old)*wce_speed)+wce_time; //adding the time that has passed multiplied with the speed factor to the WCE time
    printf("WCE time is %lu s\n",wce_time);
    wce_time_SDL_old=wce_time_SDL; //preparing for the next function call
    return wce_time; //return the time value
}

void wce_set_speed(float speed) //set the speed 1=real time and 2 is twice as fast and so one
{
    wce_speed=speed;
}

void wce_time_set(uint64_t new_time) //set the time in seconds
{
    wce_time=new_time;
}