#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int roman_to_decimal(char const r[]){
    int max_len = 0;
    max_len =(int)strlen(r);
    int result = 0;
    for (int i = 0; i < max_len; i++) {
      switch (r[i])
      {
      case 'M':
         result = result +1000;
         break;
      case 'D':
         for (int j = i+1; j < max_len; j++)// Checks if D was already used
         {
            if (r[i+1] == 'D')
            {
               return -1;
            }
         }
         if (r[i+1] == 'M')// Checks if next one is M
         {
            result = result + 500;
            i++;
         }
         else
         {
            result = result +500;
         }
         break;
      case 'C':
         if (r[i+1] == 'C' && r[i+2] == 'C' && r[i+3] == 'C')//checks if the next 3 are 'C'
         {
            return -1;
         }
         else if (r[i+1] == 'D')
         {
            result = result + 400;
            i++;
         }
         else if (r[i+1] == 'M')
         {
            result = result + 900;
            i++;
         }
         else
         {
            result = result + 100;
         }
         break;
      case 'L':
         for (int j = i+1; j < max_len; j++)//checks if L was already used
         {
            if (r[i+1] == 'L')
            {
               return -1;
            }
         }
         if (r[i+1] == 'C')
         {
            result = result + 50;
            i++;
         }
         else if (r[i+1] == 'D')
         {
            result = result + 450;
            i++;
         }
         else if (r[i+1] == 'M')
         {
            result = result + 950;
            i++;
         }
         else
         {
            result = result + 50;
         }
         break;
      case 'X':
         if (r[i+1] == 'X' && r[i+2] == 'X' && r[i+3] == 'X')//checks if the next 3 are 'X'
         {
            return -1;
         }
         else if (r[i+1] == 'L')
         {
            result = result + 40;
            i++;
         }
         else if (r[i+1] == 'C')
         {
            result = result + 90;
            i++;
         }
         else if (r[i+1] == 'D')
         {
            result = result + 490;
            i++;
         }
         else if (r[i+1] == 'M')
         {
            result = result + 990;
            i++;
         }
         else
         {
            result = result + 10;
         }
         break;
      case 'V':
         for (int j = i+1; j < max_len; j++)//checks if V was already used
         {
            if (r[i+1] == 'V')
            {
               return -1;
            }
         }
         if (r[i+1] == 'X')
         {
            result = result + 5;
            i++;
         }
         else if (r[i+1] == 'L')
         {
            result = result + 45;
            i++;
         }
         else if (r[i+1] == 'C')
         {
            result = result + 95;
            i++;
         }
         else if (r[i+1] == 'D')
         {
            result = result + 495;
            i++;
         }
         else if (r[i+1] == 'M')
         {
            result = result + 995;
            i++;
         }
         else
         {
            result = result + 5;
         }
         break;
      case 'I':
         if (r[i+1] == 'I' && r[i+2] == 'I' && r[i+3] == 'I')//checks if the next 3 are 'I'
         {
            return -1;
         }
         else if (r[i+1] == 'V')
         {
            result = result + 4;
            i++;
         }
         else if (r[i+1] == 'X')
         {
            result = result + 9;
            i++;
         }
         else if (r[i+1] == 'L')
         {
            result = result + 49;
            i++;
         }
         else if (r[i+1] == 'C')
         {
            result = result + 99;
            i++;
         }
         else if (r[i+1] == 'D')
         {
            result = result + 499;
            i++;
         }
         else if (r[i+1] == 'M')
         {
            result = result + 999;
            i++;
         }
         else
         {
            result = result + 1;
         }
         break;
      default:
         return -1;//This means one of the given rules were broken
      }
   }
   return result;
}

void decimal_to_roman(int d, char r[]){
   int result = d;
   while(result != 0)
   {
      if (result >= 1000)
      {
         strncat(r,"M",1);
         result -= 1000;
      }
      else if (result >= 900)
      {
         if (result == 999)
         {
            strncat(r,"IM",2);
            result -= 999;
         }
         else if(result == 995)
         {
            strncat(r,"VM",2);
            result -= 995;
         }
         else if(result == 990)
         {
            strncat(r,"XM",2);
            result -= 990;
         }
         else if(result == 950)
         {
            strncat(r,"LM",2);
            result -= 950;
         }
         else
         {
            strncat(r,"CM",2);
            result -= 900;
         }
      }        
      else if (result >= 500)
      {           
         strncat(r,"D",1);
         result -= 500;
      }
      else if (result >= 400)
      {
         if (result == 499)
         {
            strncat(r,"ID",2);
            result -= 499;
         }
         else if (result == 495)
         {
            strncat(r,"VD",2);
            result -= 495;
         }
         else if (result == 490)
         {
            strncat(r,"XD",2);
            result -= 490;
         }
         else if (result == 450)
         {
            strncat(r,"LD",2);
            result -= 450;
         }
         else
         {
            strncat(r,"CD",2);
            result -= 400;
         }
      }
      else if (result >= 100)
      {
         strncat(r,"C",1);
         result -= 100;                       
      }
      else if(result == 99)
      {
         strncat(r,"IC",2);
         result -= 99;
      }
      else if(result == 95)
      {
         strncat(r,"VC",2);
         result -= 95;
      }
      else if(result == 90)
      {
         strncat(r,"XC",2);
         result -= 90;
      }
      else if (result >= 50)
      {
         strncat(r,"L",1);
         result -= 50;                                                                     
      }
      else if (result >= 40)
      {
         if (result == 49)
         {
            strncat(r,"IL",2);          
            result -= 49;
         }
         else if(result==45)
         {
            strncat(r,"VL",2);          
            result -= 45;
         }
         else if(result==45)
         {
            strncat(r,"VL",2);          
            result -= 45;
         }
         else
         {
            strncat(r,"XL",2);          
            result -= 40;
         }
      }
      else if (result >= 10)
      {
         strncat(r,"X",1);
         result -= 10;           
      }
      else if (result >= 9)
      {
         strncat(r,"IX",2);
         result -= 9;                         
      }
      else if (result >= 5)
      {
         strncat(r,"V",1);
         result -= 5;                                     
      }
      else if (result >= 4)
      {
         strncat(r,"IV",2);
         result -= 4;                                                            
      }
      else if (result >= 1)
      {
         strncat(r,"I",1);
         result -= 1;                                                                                   
      }
   }
}


int main(){
   int test = 0;
   char te2[10];
   test = roman_to_decimal("MCMLXV");
   decimal_to_roman(1965,te2);
   printf("%d\n",test);
   printf("%s\n",te2);
}