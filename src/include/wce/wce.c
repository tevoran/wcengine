#include "wce.h"

#include <stdio.h>

//global variables
char wce_planet_name[]="";


int wce_create_planet(long seed)
{
    //printf("Creating planet from seed\n");
    
    //generating name of the planet
    
    //data sets
    char initial_letter[16]={"BDFGHJKLMNPRSTVY"};
    char vowel[5]={"aeiou"};
    char consonant[16]={"bdfghjklmnprstvy"};
    
    char reserved_space_name[24];
    char *name_of_planet=&reserved_space_name[0];
    
    long later_seed=seed; //copying seed nummer
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
    
    printf("Planet name: %s\n", reserved_space_name);
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