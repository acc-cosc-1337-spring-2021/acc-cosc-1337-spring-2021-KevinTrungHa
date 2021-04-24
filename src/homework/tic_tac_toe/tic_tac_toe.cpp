//cpp (implementation)
#include "tic_tac_toe.h"
#include <iostream>
using std::cout; using std::cin;

//Public functions of class TicTacToe

//Friend functions:
std::ostream& operator<<(std::ostream& out, const TicTacToe& game) 
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
        
        if(i == 2 || i == 5 || i == 8) 
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
        
        if(i == 3 || i == 7 || i == 11 || i == 15)  
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

  //Decide between 3x3 or 4x4 grid
  if(game.pegs.size() == 9)  //3x3 board size
  {
    //Pasted from main:
    int position;
    
    do
    {
          
      cout<<"It is " << game.get_player() << "'s turn. \n"; 
      cout<<"Enter an integer position (1-9): \n";  
      in>> position;
    }
    while(!(position <= 9 && position >= 1));

    game.mark_board(position); 

    return in;
  }
  else if(game.pegs.size() == 16)
  {
    int position;
    
    do
    {
          
      cout<<"It is " << game.get_player() << "'s turn. \n"; 
      in>> position;
    }
    while(!(position <= 16 && position >= 1)); 

    game.mark_board(position); 

    return in;
  }
  return in; 
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
  else if(check_board_full() == true) 
  {
    winner = "C"; 
    return true;
  }
  else 
  {
    return false;
  }
}

void TicTacToe::start_game(string first_player)
{
  
  if(first_player == "X" || first_player == "O")
  {
    player = first_player; 

    clear_board(); 
  }
  else
  {
    cout<<"Error starting game. void start_game fcn error \n"; 
  }
}

void TicTacToe::mark_board(int position)
{
 
  pegs.at(position-1) = player;  

  set_next_player();
}

string TicTacToe::get_player() const
{
  return player;
}


string TicTacToe::get_winner() const
{
  return winner;
}



bool TicTacToe::check_column_win()
{

  return false;
  
}

bool TicTacToe::check_row_win()
{

  return false;
}

bool TicTacToe::check_diagonal_win()
{
  
  return false;
}

void TicTacToe::set_winner()
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
  return true; 
}

void TicTacToe::clear_board()
{
  for(auto& peg: pegs)
  {
    peg = " ";
  }
  
}