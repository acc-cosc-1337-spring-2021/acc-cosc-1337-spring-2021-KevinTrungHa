//cpp (implementation)
#include "tic_tac_toe.h"
#include <iostream>
using std::cout; using std::cin;

//Public functions of class TicTacToe

//Friend functions:
std::ostream& operator<<(std::ostream& out, const TicTacToe& game)  //Usage: in main, cout<<game.   Replaces output to screen
{
  out<<"Displaying board: \n";

  //Decide between 3x3 or 4x4 board
  if(game.pegs.size() == 9)  //3x3 board size
  {
    //Displays 3x3 board
    //Iterate through vector to display board in 3x3 format
    for(int i = 0; i < 9; i++)
      {
        out<<game.pegs[i];

        if(i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)
        {
          out<<"|";
        }
        
        if(i == 2 || i == 5 || i == 8)  //Line break after first, second, and third row are printed out
        {
          out<<"\n";
        }
      }
    return out;
  }
  else if(game.pegs.size() == 16)  //4x4 board size
  {
    //Iterate through vector to display board in 4x4 format
    for(int i = 0; i < 16; i++)
      {
        out<<game.pegs[i];

        if(i==0 || i==1 || i==2 || i==4 || i==5 || i==6 || i==8 || i==9 || i==10 || i==12 || i == 13 || i ==14)
        {
          out<<"|";
        }
        
        if(i == 3 || i == 7 || i == 11 || i == 15)  //Line break after first, second, third, and fourth row are printed out
        {
          out<<"\n";
        }
      }
    return out;
  }
  return out;  //Maybe problematic
}

std::istream& operator>>(std::istream& in, TicTacToe& game)   //Replaces code that captures keyboard data
{
  //The cin for position code that we removed from main should be in this fcn
  //ts going to pull like game.balance (or some function)

  //Decide between 3x3 or 4x4 grid
  if(game.pegs.size() == 9)  //3x3 board size
  {
    //Pasted from main:
    int position;
    
    do
    {
          
      cout<<"It is " << game.get_player() << "'s turn. \n"; //Use string get_player() const function to say who's turn it is.
      cout<<"Enter an integer position (1-9): \n";  
      in>> position;
    }
    while(!(position <= 9 && position >= 1)); //Validates input position to be 1-9

    game.mark_board(position); 

    return in;
  }
  else if(game.pegs.size() == 16)
  {
    int position;
    
    do
    {
          
      cout<<"It is " << game.get_player() << "'s turn. \n"; //Use string get_player() const function to say who's turn it is.
      cout<<"Enter an integer position (1-16): \n";  
      in>> position;
    }
    while(!(position <= 16 && position >= 1)); //Validates input position to be 1-9

    game.mark_board(position); 

    return in;
  }
  return in;  //Also might be problematic
}

bool TicTacToe::game_over()
{
  if(check_column_win() == true)
  {
    set_winner();
    return true;
  }
  else if(check_row_win() == true)
  {
    set_winner();
    return true;
  }
  else if(check_diagonal_win() == true)
  {
    set_winner();
    return true;
  }
  else if(check_board_full() == true) //This only trips if column, row, and diagonal functions return false. Thus triggers tie.
  {
    winner = "C"; //Stands for CAT
    return true;
  }
  else //Only trips if column, row, and diagnal fcns return false AND there is no tie
  {
    return false;
  }
}

void TicTacToe::start_game(string first_player)
{
  //Ensure function argument is X or O 
  if(first_player == "X" || first_player == "O")
  {
    player = first_player;  //player is a private string in the class

    clear_board(); 
  }
  else
  {
    cout<<"Error starting game. void start_game fcn error \n"; 
  }
}

void TicTacToe::mark_board(int position)
{
  //"Mark vector w position -1 equal to player"
  pegs.at(position-1) = player;  //Writes over position with X or O in vector

  set_next_player();
}

string TicTacToe::get_player() const
{
  return player; //Player is always X or O
}

/* Removed fcn; replaced w/ overloading
void TicTacToe::display_board() const
{
  //Iterate through vector to display board in 3x3 format
  for(int i = 0; i < 9; i++)
    {
      cout<<pegs[i];
      if(i == 0 || i == 1 || i == 3 || i == 4 || i == 6 || i == 7)
      {
        cout<<"|";
      }
      
      if(i == 2 || i == 5 || i == 8)  //Line break after first, second, and third row are printed out
      {
        cout<<"\n";
      }
    }
}
*/

string TicTacToe::get_winner() const
{
  return winner;
}

//Private functions of class TicTacToe

bool TicTacToe::check_column_win()
{
  /* All these conditions have been pasted into derrived class fcns; Now, this only returns false
  
  //X win conditions
  if(pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X")
  {
    return true;
  }
  else if(pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X")
  {
    return true;
  }
  else if(pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X")
  {
    return true;
  }
  //O win condition
  if(pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O")
  {
    return true;
  }
  else if(pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O")
  {
    return true;
  }
  else if(pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O")
  {
    return true;
  }
  else //If nobody wins, fcn returns false
  {
    return false;
  }
  */

  return false;
  
}

bool TicTacToe::check_row_win()
{
  /*
  //X win conditions
  if(pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X")
  {
    return true;
  }
  else if(pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X")
  {
    return true;
  }
  else if(pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")
  {
    return true;
  }
  //O win condition
  if(pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O")
  {
    return true;
  }
  else if(pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O")
  {
    return true;
  }
  else if(pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O")
  {
    return true;
  }
  else //If nobody wins, fcn returns false
  {
    return false;
  }
  */
  return false;
}

bool TicTacToe::check_diagonal_win()
{
  /*
  //X win conditions
  if(pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")
  {
    return true;
  }
  else if(pegs[6] == "X" && pegs[4] == "X" && pegs[2] == "X")
  {
    return true;
  }
  //O win conditions
  if(pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
  {
    return true;
  }
  else if(pegs[6] == "O" && pegs[4] == "O" && pegs[2] == "O")
  {
    return true;
  }
  else //If nobody wins, fcn returns false
  {
    return false;
  }
  */
  return false;
}

void TicTacToe::set_winner()  //Diagnose the backend of this fcn
{
  if(player == "X")
  {
    winner = "O";
  }
  else if(player == "O")
  {
    winner = "X";
  }
  else
  {
    cout<<"Error running set_winner function. \n";
  }
}


void TicTacToe::set_next_player()
{
  //Switches string player from X to O; or from O to X. It flip-flops.
  if(player == "X")
  {
    player = "O";
  }
  else if(player == "O")
  {
    player = "X";
  }
  else
  {
    cout<<"Error running set_next_player function. Input was not X or O";
  }
}

bool TicTacToe::check_board_full()
{
  //Check for " " (space) in board string vector
  for(string peg : pegs)
  {
    if(peg == " ")
    {
      return false;
    }
  }
  return true; //This only trips if the program goes through the for loop loop without triggering the return false (in if statement)
}

void TicTacToe::clear_board()
{
  for(auto& peg: pegs)
  {
    peg = " ";
  }
  
  //for(std::size_t i = 0; i < pegs.size(); i++) Old loop
}