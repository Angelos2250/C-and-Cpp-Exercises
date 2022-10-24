#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

   int min = 0;
   int max = 0;
   int currentNumber;

   for (int i = 1; i < argc; i++) /* Für jedes Argument */
   {
      currentNumber = atoi(argv[i]);
      if (currentNumber < 0 && min > currentNumber)
      {
         min = currentNumber;
      }
      if (currentNumber > 0 && max < currentNumber)
      {
         max = currentNumber;
      } 
   }
   
   printf("min=%-d\nmax=%d\n",min,max);

   return EXIT_SUCCESS;

}