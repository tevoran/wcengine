#include "wce.h"


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