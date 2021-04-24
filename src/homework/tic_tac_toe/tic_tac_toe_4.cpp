#include "tic_tac_toe_4.h"

/*
class function check_column_win
Win by column if and return true if (each column index)
0, 1,  2,  3 
4, 5,  6,  7 
8, 9, 10, 11 
12,13,14, 15 
else
false
*/

bool TicTacToe4::check_column_win()
{
  //X win conditions
  if(pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X" && pegs[12] == "X")
  {
    return true;
  }
  else if(pegs[1] == "X" && pegs[5] == "X" && pegs[9] == "X" && pegs[13] == "X")
  {
    return true;
  }
  else if(pegs[2] == "X" && pegs[6] == "X" && pegs[10] == "X" && pegs[14] == "X")
  {
    return true;
  }
  else if(pegs[3] == "X" && pegs[7] == "X" && pegs[11] == "X" && pegs[15] == "X")
  {
    return true;
  }
  
  //O win condition
  if(pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O" && pegs[12] == "O")
  {
    return true;
  }
  else if(pegs[1] == "O" && pegs[5] == "O" && pegs[9] == "O" && pegs[13] == "O")
  {
    return true;
  }
  else if(pegs[2] == "O" && pegs[6] == "O" && pegs[10] == "O" && pegs[14] == "O")
  {
    return true;
  }
  else if(pegs[3] == "O" && pegs[7] == "O" && pegs[11] == "O" && pegs[15] == "O")
  {
    return true;
  }
  else //If nobody wins, fcn returns false
  {
    return false;
  }
}


bool TicTacToe4::check_row_win()
{
  //X win conditions
  if(pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X" && pegs[3] == "X")
  {
    return true;
  }
  else if(pegs[4] == "X" && pegs[5] == "X" && pegs[6] == "X" && pegs[7] == "X")
  {
    return true;
  }
  else if(pegs[8] == "X" && pegs[9] == "X" && pegs[10] == "X" && pegs[11] == "X")
  {
    return true;
  }
  else if(pegs[12] == "X" && pegs[13] == "X" && pegs[14] == "X" && pegs[15] == "X")
  {
    return true;
  }
  
  //O win conditions
  if(pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O" && pegs[3] == "O")
  {
    return true;
  }
  else if(pegs[4] == "O" && pegs[5] == "O" && pegs[6] == "O" && pegs[7] == "O")
  {
    return true;
  }
  else if(pegs[8] == "O" && pegs[9] == "O" && pegs[10] == "O" && pegs[11] == "O")
  {
    return true;
  }
  else if(pegs[12] == "O" && pegs[13] == "O" && pegs[14] == "O" && pegs[15] == "O")
  {
    return true;
  }
  else //If nobody wins, fcn returns false
  {
    return false;
  }
}

bool TicTacToe4::check_diagonal_win()
{
  //X win conditions
  if(pegs[0] == "X" && pegs[5] == "X" && pegs[10] == "X" && pegs[15] == "X")
  {
    return true;
  }
  else if(pegs[12] == "X" && pegs[9] == "X" && pegs[6] == "X" && pegs[3] == "X")
  {
    return true;
  }

  //O win conditions
  if(pegs[0] == "O" && pegs[5] == "O" && pegs[10] == "O" && pegs[15] == "O")
  {
    return true;
  }
  else if(pegs[12] == "O" && pegs[9] == "O" && pegs[6] == "O" && pegs[3] == "O")
  {
    return true;
  }
  else //If nobody wins, fcn returns false
  {
    return false;
  }
}