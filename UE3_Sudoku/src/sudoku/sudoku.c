#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SUDOKU_LENGTH 9
static void print_grid(const int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH],const int length);
static bool number_fits(const int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH],int x,int y,int num);
static void sudoku(int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH]);
static bool solve_sudoku(int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH],int row, int col);
static bool number_in_3x3(int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH], int x,int y, int num);
static bool filled_grid(const int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH]);

static bool solve_sudoku(int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH],int row, int col){
   for (int i = row; i < MAX_SUDOKU_LENGTH; i++){ //go through every row
      for (int j = col; j < MAX_SUDOKU_LENGTH; j++){ //go through every col
         if (grid[i][j] == 0) //check if spot is filled or not
         {
            for (int k = 1; k <= 9; k++){ //Check if any of the numbers 1-9 fit
               if (number_fits(grid,i,j,k))
               {
                  grid[i][j] = k; //Set number in empty spot (temporarly)
                  if (solve_sudoku(grid,row,col))// recursion
                  {
                     return true;
                  }
                  else
                  {
                     grid[i][j] = 0; //this means solving sudoku failed so set empty space to 0 and try again
                  }
               }
            }
            grid[i][j] = 0;
            return false; //this is our backtracking trigger
         }
      }
   }// by this time every empty spot is filled so the sudoku is solved
   return true;
}

static void sudoku(int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH]){
   if (!filled_grid(grid))
   {
      printf("DONE\n");
      print_grid(grid,9);
   }
   else
   {
      solve_sudoku(grid,0,0);
      printf("DONE2\n");
   }
}

static bool filled_grid(const int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH]){
   int row;
   int col;
   for (row = 0; row < MAX_SUDOKU_LENGTH; row++)
   {
      for (col = 0; col < MAX_SUDOKU_LENGTH; col++)
      {
         if (grid[row][col] == 0) //checks if grid is filles (=> sudoku solved)
         {
            return true;
         }
      }
   }
   return false;
}

static void print_grid(const int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH],const int length){
   for (int i = 0; i < length; i++)
   {
      for (int j = 0; j < length; j++)
      {
         printf("%d ",grid[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

static bool number_in_3x3(int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH], int x,int y, int num)
{
   bool res = false;
   for (int row = 0; row < 3; row++){
      for (int col = 0; col < 3; col++){
         if (grid[row + (x-(x%3))][col + (y-(y%3))] == num){ //checks if given number is in the 3x3 subgrid
            res = true;
            return res;
         }   
      }
   }
   res = false;
   return res;
}
   
static bool number_fits(const int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH],int x,int y,int num){
   bool res = false;
   if ((number_in_3x3(grid,x,y,num)))
   {
      return res; //number in 3x3 return false
   }
   for (int i = 0; i < MAX_SUDOKU_LENGTH; i++)
   {
      if ((grid[x][i] == num) || //NUMBER IN Row
          (grid[i][y] == num))   //Number in Col
      {
         res = false;
         return res;
      }
      else
      {
         res = true;
      }
   }
   return res;
}

int main() {
   printf("Sudoku Problem\n");
   
   // int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH] 
   // = {{5,3,0,0,7,0,0,0,0},
   //    {0,9,8,0,0,0,0,6,0},
   //    {6,0,0,1,9,5,0,0,0},
   //    {8,0,0,0,6,0,0,0,3},
   //    {4,0,0,8,0,3,0,0,1},
   //    {7,0,0,0,2,0,0,0,6},
   //    {0,6,0,0,0,0,2,8,0},
   //    {0,0,0,4,1,9,0,0,5},
   //    {0,0,0,0,8,0,0,7,9}};
   int grid[MAX_SUDOKU_LENGTH][MAX_SUDOKU_LENGTH] 
   = {{0,0,9,0,8,5,0,0,0},
      {0,6,0,0,0,0,0,0,9},
      {0,7,8,0,0,0,0,1,4},
      {0,0,0,0,0,0,0,0,0},
      {0,0,5,0,1,8,0,0,0},
      {0,0,0,7,0,0,4,8,2},
      {0,0,0,0,0,7,0,4,0},
      {2,0,0,6,0,9,0,0,0},
      {0,8,0,0,0,0,0,7,0}};
   clock_t solved;
   clock_t unsolved = clock();
   sudoku(grid);
   solved = clock();
   double time = 1000*(solved - unsolved)/CLOCKS_PER_SEC;
   print_grid(grid,MAX_SUDOKU_LENGTH);
   printf("time to solve: %f miliseconds\n",time);
  return EXIT_SUCCESS;
}