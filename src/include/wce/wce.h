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
};


struct planet wce_create_planet(long seed);
long wce_random(long seed);

#endif