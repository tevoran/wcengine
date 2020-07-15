#include "wce.h"

#include <stdio.h>
#include <inttypes.h>
#include <math.h>


struct planet wce_create_planet(long seed)
{
    printf("Creating planet from seed\n");
    
    struct planet world;    
    //generating name of the planet
    //
    
    //data sets
        char initial_letter[16]={"BDFGHJKLMNPRSTVY"};
        char vowel[5]={"aeiou"};
        char consonant[16]={"bdfghjklmnprstvy"};
    
        char *name_of_planet=&world.name[0];
    
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
    
        printf("Planet name: %s\n", world.name);

    

    //creating temperature of the planets sun
    printf("Creating sun\n");
    
        int temperature_range;
    
        later_seed=wce_random(later_seed);
        temperature_range=later_seed%5;//it is more likely to have a dimmer sun than a brighter one
        if(temperature_range==4)
        {
            later_seed=wce_random(later_seed);
            world.sun_temperature=(later_seed%18000)+1800;
        }
        if(temperature_range!=4)
        {
            later_seed=wce_random(later_seed);
            world.sun_temperature=(later_seed%4000)+1800;
        }
        printf("Planet's sun's temperature is: %lu Kelvin\n",world.sun_temperature);

        //creating diameter of the planets sun

        int size_range;

        later_seed=wce_random(later_seed);
        size_range=later_seed%5;
    
        //it is more likely to have a smaller sun than a bigger one
        if(size_range==4)
        {
            later_seed=wce_random(later_seed);
            world.sun_size=later_seed*1000;
        }
        if(size_range!=4)
        {
            later_seed=wce_random(later_seed);
            world.sun_size=(later_seed%2000000)*1000;
        }
        printf("Planet's sun's size is: %lu Meter\n",world.sun_size);
    
    
        //calculating sun's luminosity
        double luminosity_sun;
    
        //luminosity formula for stars
        double four_pi=4*3.1415;
        double size_square=(world.sun_size/2)*(world.sun_size/2);
        double temperature_four=(world.sun_temperature)*(world.sun_temperature)*(world.sun_temperature)*(world.sun_temperature);
        world.sun_luminosity=four_pi*size_square*5.670373*0.00000001*temperature_four;
    
        //compare luminosity with our sun
        luminosity_sun=world.sun_luminosity/10000000000;
        luminosity_sun=luminosity_sun/10000000000;
        luminosity_sun=luminosity_sun/3900000;
        printf("Luminosity of star is %f suns\n",luminosity_sun);
        
        
        //creating the planet's albedo
        later_seed=wce_random(later_seed);
        world.albedo=((float)(later_seed%200)/1000)+0.2;
        printf("Albedo: %f\n",world.albedo);
        
        //creating surface temperature without the greenhouse effect and the distance between sun and planet
        world.black_temperature=0;
        
        int i=0;
        while((world.black_temperature<200 || world.black_temperature>300) && i<999)
        {
            later_seed=wce_random(later_seed);
            world.sun_distance=later_seed*1000;
        
            double albedo_4_sqrt=sqrt(sqrt((1-world.albedo)));// (1-a)^1/4
            double sqrt_radii=sqrt((double)(world.sun_size/(4*(double)world.sun_distance))); // (R/2a)^1/2
            world.black_temperature=(double)(albedo_4_sqrt*sqrt_radii*(double)world.sun_temperature);

            i++;
        }
        
            if(i==999)
            {  
                printf("[ERROR] error while creating planet, there was no suitable distance found\n");
                return world;
            }
            printf("Distance %lu km\n",(world.sun_distance/1000));
            
        //adding greenhouse effect
        later_seed=wce_random(later_seed);
        world.greenhouse=later_seed%70;
        printf("Additional greenhouse effect with %u Kelvin\n",world.greenhouse);
        world.temperature=world.greenhouse+world.black_temperature;
        
            printf("Planetary temperature: %li °C\n",((signed long)world.temperature-273));
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