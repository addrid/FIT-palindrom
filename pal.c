#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

unsigned long long int mirror(unsigned long long int number)
{
   int n=0, a=0, supp, i;
   unsigned long long int mirrored=number, array[21], neco=1;      
         
   while(mirrored > 0)
   {
      array[n] = mirrored%10;
      mirrored/=10;
      n++;               
   }
   for(i=0;i<n-1;i++)
     {  
        neco=neco*10;
     }
   
   mirrored = 0;
   while(a!=n)
   {
      supp = n-(a+1);
      mirrored += array[a]*neco;    
      a++;
      neco/=10;
   }
   
   return mirrored;     
}

int main(int argc, char *argv[])
{
unsigned long long int number, mirrored, test, test2; 
int interac=0, firstRun=0;   
    
printf("Zadejte cislo:\n");
if(scanf("%llu",&number)!=1 || number <0)
{                        
     printf("Nespravny vstup.\n");
     return 1;
}  

mirrored = mirror(number);
while(number+mirrored > mirrored && number+mirrored > number)
{
    if(firstRun!=0)
    {
        mirrored = mirror(number);
    }
    firstRun++;
    test = number;
    test2 = mirrored;
    
    if(number!=mirrored)
    {
       number+=mirrored;             
       interac++;
       if(number+mirrored < test || number+mirrored < test2)
       {
        printf("Palindrom nenalezen.\n");
        return 1;
       }                  
    } 
    else
    {         
       printf("Vypocteny palindrom: %llu (iteraci: %d)\n", mirrored, interac);
       return 0;
    } 
}
if(number+mirrored < mirrored || number+mirrored < number)
                   {
                    printf("Palindrom nenalezen.\n");
                    return 1;
                   }
  
#ifndef __PROGTEST__
  system ( "pause" ); /* toto progtest "nevidi" */
#endif /* __PROGTEST__ */
  return 0;
} 

