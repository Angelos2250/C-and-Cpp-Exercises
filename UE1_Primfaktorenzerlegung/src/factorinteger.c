#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

   int currentNumber;

   for (int i = 1; i < argc; i++) /*für jedes Argument*/
   {
      currentNumber = atoi(argv[i]);

      if (currentNumber < 0) /*negative Zahlen müssen extra behandelt werden */
      {
         printf("Only positive Numbers\n");
         return EXIT_FAILURE;
      }
      else if (currentNumber == 1) /* 1 muss extra behandelt werden */
      {
         printf("%d: {",1);
         printf("{%d,%d}}\n",1,1);

      }
      else if (currentNumber == 0)/* 0 muss extra behandelt werden */
      {
         printf("%d: {",0);
         printf("{%d,%d}}\n",0,1);

      }
      else {
         int j = 2;
         int primfaktor = 2;
         int exponent = 0;
         printf("%d: {",currentNumber);
         while (j < currentNumber)
         {
            while(currentNumber%j != 0){ /* Finde den nächsten Primfaktor */
               j++;
            }
            while (currentNumber%j == 0){ 
               currentNumber /=j;
               if (primfaktor == j)
               {
                  exponent++;
               }else{
                  if (exponent != 0)
                  {              
                  printf("{%d,%d},",primfaktor,exponent);
                  }
                  primfaktor = j;
                  exponent = 1;
               }
            }
         }
         printf("{%d,%d}",primfaktor,exponent);
         printf("}");
         printf("\n");
      }
   }
   return EXIT_SUCCESS;
}