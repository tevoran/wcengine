#include "wce.h"

#include <stdio.h>

//global variables
char wce_planet_name[]="";


int wce_create_planet(long seed)
{
    printf("Creating planet from seed\n");
    
    //generating name of the planet
    //
    //data sets
        char initial_letter[16]={"BDFGHJKLMNPRSTVY"};
        char vowel[5]={"aeiou"};
        char consonant[16]={"bdfghjklmnprstvy"};
    
    char reserved_space[40]; //reserved space for the name and all the other data about the world
        char *name_of_planet=&reserved_space[0];
    
        long later_seed=wce_random(seed); //copying seed nummer
        int letter;//letter lottery
    
        int number_of_syllables=(later_seed%7)+1;
        later_seed=wce_random(later_seed); //making new seed
        //printf("Number of syllables for planet name: %i\n",number_of_syllables);
    
        //initial letter of the name
        letter=later_seed%16; //getting the random initial letter
        later_seed=wce_random(later_seed);//making new seed
        *name_of_planet=initial_letter[letter];//writing initial letter to memory
    
        //first vowel
        letter=later_seed%5;//getting random vowel
        later_seed=wce_random(later_seed);//making new seed
        name_of_planet++;//increase pointer adress
        *name_of_planet=vowel[letter];
    
        //decrease syllable counter
        number_of_syllables--;
    
        //syllable loop
        while(number_of_syllables>0)
        {
            //consonant
            letter=later_seed%16;//getting consonant
            later_seed=wce_random(later_seed);//making new seed
            name_of_planet++;//increment pointer
            *name_of_planet=consonant[letter];//writing letter
        
            //vowel
            letter=later_seed%5;//getting vowel
            later_seed=wce_random(later_seed);//making new seed
            name_of_planet++;//increment pointer
            *name_of_planet=vowel[letter];//writing letter
        
            //decrease syllable counter
            number_of_syllables--;
        }
    
        //add zero termination
        name_of_planet++;
        *name_of_planet=0;
    
        printf("Planet name: %s\n", reserved_space);

    

    //creating temperature of the planets sun
    printf("Creating sun\n");
    
        long *sun_temperature=(long*)&reserved_space[15];
    
        int temperature_range;
    
        later_seed=wce_random(later_seed);
        temperature_range=later_seed%5;//it is more likely to have a dimmer sun than a brighter one
        if(temperature_range==4)
        {
            later_seed=wce_random(later_seed);
            *sun_temperature=(later_seed%18000)+1800;
        }
        if(temperature_range!=4)
        {
            later_seed=wce_random(later_seed);
            *sun_temperature=(later_seed%4000)+1800;
        }
        printf("Planet's sun's temperature is: %li Kelvin\n",*sun_temperature);

        //creating diameter of the planets sun
        long *sun_size=(long *)&reserved_space[23];

        int size_range;

        later_seed=wce_random(later_seed);
        size_range=later_seed%5;
    
        //it is more likely to have a smaller sun than a bigger one
        if(size_range==4)
        {
            later_seed=wce_random(later_seed);
            *sun_size=later_seed*1000;
        }
        if(size_range!=4)
        {
            later_seed=wce_random(later_seed);
            *sun_size=(later_seed%2000000)*1000;
        }
        printf("Planet's sun's size is: %li Meter\n",*sun_size);
    
    
        //creating distance between the planet and the sun
        long long *planet_distance=(long long*)&reserved_space[31];
        double luminosity;
        double luminosity_sun;
    
        //luminosity formula for stars
        double four_pi=4*3.1415;
        double size_square=((*sun_size)/2)*((*sun_size)/2);
        double temperature_four=(*sun_temperature)*(*sun_temperature)*(*sun_temperature)*(*sun_temperature);
    
        luminosity=four_pi*size_square*5.670373*0.00000001*temperature_four;
    
        //compare luminosity with our sun
        luminosity_sun=luminosity/10000000000;
        luminosity_sun=luminosity_sun/10000000000;
        luminosity_sun=luminosity_sun/3900000;
        printf("Luminosity of star is %f suns\n",luminosity_sun);
        
    
    
}

//randomgenerator (after Blum-Blum-Shub)
//seed has max. 9 decimals
//the output has also max 9 decimals
long wce_random(long seed)
{
  long p=10007;
  long q=100003;
  long n=p*q;
  long output;
  output=seed;
  while(1)
    {
      output=(output*output)%n;
        if(output<1000000000)
        {
            break;
        }
    }  
  return output;
}