#include <iostream>
using namespace std;
int grid[9][9];
bool isPresentInCol(int col, int num){ //check whether num is present in col or not
   for (int row = 0; row < 9; row++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInRow(int row, int num){ //check whether num is present in row or not
   for (int col = 0; col < 9; col++)
      if (grid[row][col] == num)
         return true;
   return false;
}
bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
//check whether num is present in 3x3 box or not
   for (int row = 0; row < 3; row++)
      for (int col = 0; col < 3; col++)
         if (grid[row+boxStartRow][col+boxStartCol] == num)
            return true;
   return false;
}
void sudokuGrid(){ //print the sudoku grid after solve
    cout<<"Solved sudoku : \n";
   for (int row = 0; row < 9; row++){
      for (int col = 0; col < 9; col++){
         if(col == 3 || col == 6)
            cout << " | ";
         cout << grid[row][col] <<" ";
      }
      if(row == 2 || row == 5){
         cout << endl;
         for(int i = 0; i<9; i++)
            cout << "---";
      }
      cout << endl;
   }
}
bool findEmptyPlace(int &row, int &col){ //get empty location and update row and column
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (grid[row][col] == 0) //marked with 0 is empty
            return true;
   return false;
}
bool isValidPlace(int row, int col, int num){
   //when item not found in col, row and current 3x3 box
   return !isPresentInRow(row, num) && !isPresentInCol(col, num) && !isPresentInBox(row - row%3 ,
col - col%3, num);
}
bool solveSudoku(){
   int row, col;
   if (!findEmptyPlace(row, col))
      return true; //when all places are filled
   for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
      if (isValidPlace(row, col, num)){ //check validation, if yes, put the number in the grid
         grid[row][col] = num;
         if (solveSudoku()) //recursively go for other rooms in the grid
            return true;
         grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
      }
   }
   return false;
}
int main(){
    cout<<"Enter the sudoku using 0 for blank spaces : \n";
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
        cin>>grid[i][j];
    }
   if (solveSudoku() == true)
      sudokuGrid();
   else
      cout << "No solution exists";
}