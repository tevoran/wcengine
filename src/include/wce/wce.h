#ifndef WCE_H
#define WCE_H

#include <inttypes.h>

//structs
struct planet
{
    char name[16];
    uint64_t sun_temperature; // sun temparature in Kelvin
    uint64_t sun_size;  //sun size in meters
    uint64_t sun_distance; // distance of planet and sun in meters
    double sun_luminosity; // sun's luminosity in watts
    float albedo;   // world's albedo
    uint32_t black_temperature; // world's mean black body temperature in Kelvin
    uint32_t greenhouse; //greenhouse effect additional temperature in Kelvin
    uint32_t temperature; //temperature including black body temperature and greenhouse effect
    uint64_t year;  //time that's necessary for a year in seconds
    uint64_t day;   //time for one day on the planet in seconds
    float axis_tilt; //tilt of the rotation axis
    uint64_t size; //planetary diameter in meters
    double density; //planetary density
    double g;    //planetary gravity
};

//time variable

uint64_t wce_time; //time in seconds
uint64_t wce_time_SDL; //the SDL time
float wce_speed; //the speed of the engine

//functions
struct planet wce_create_planet(long seed);
long wce_random(long seed);

    //time functions
    void wce_time_start(); //start the time counter
    uint64_t wce_time_get(); //get the current time in s
    void wce_time_set(uint64_t new_time); //set the time in seconds
    void wce_set_speed(float speed); //set the speed 1=real time and 2 is twice as fast and so one

#endif