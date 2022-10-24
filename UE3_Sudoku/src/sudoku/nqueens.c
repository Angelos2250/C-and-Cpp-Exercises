#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100

static bool queen_fits (const int col[], int i, int j);
static void place_queen(int col[], int i, int n);
static void print_solution(const int col[],int n);

static int n_solution = 0;

static void place_queen(int col[], int i, int n){
   int j;
   for ( j = 1; j <= n; j++)
   {
      if (queen_fits(col,i,j))
      {
         col[i] = j;
         if (i == n)
         {
            print_solution(col,n);
         }else
         {
            place_queen(col, i+1, n);
         }
         col[i] = 0;
         
      }
      
   }
   
}

static bool queen_fits(const int col[], int i, int j) {
	int k;
	for (k = 1; k < i; k++) {
		if (( col[k] == j ) || //
			  (k+col[k] == i+j) ||
			  (k-col[k] == i-j))
		return false; 
	} /*for*/
	return true;
} /* queen_fits */

static void print_solution(const int col[],int n){
   n_solution++;
   printf("solution %d:\n",n_solution);

   for (int i = 1; i <= n; i++)
   {
      printf("%4d:", i);
      for (int j = 0;j <= n;j++)
      {
         if (j != col[i])
         {
            printf("- ");
         }
         else
         {
            printf("D ");
         }
      }
      printf("\n");      
   }
   printf("\n");
}

int main() {
   printf("N Queens Problem\n");

   int col[MAX_N+1];
   int n=4;
   for (int i = 1; i <= n; i++)
   {
      col[i]=0;
   }
   place_queen(col,1,n);
  return EXIT_SUCCESS;
}