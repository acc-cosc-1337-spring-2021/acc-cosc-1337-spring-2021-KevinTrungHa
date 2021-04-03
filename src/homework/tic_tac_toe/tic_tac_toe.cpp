//cpp

#include "tic_tac_toe.h"
#include <iostream>
using std::cout;
using std::cin;


//Public functions of class Tictactoe
bool TicTacToe::game_over()
{
    return check_board_full();
}

//start_game
void TicTacToe::start_game(string first_player)
{
    //first_player function argument value must be X or O
    //using if else function
    if (first_player == "X" || first_player == "O")
    {
        player = first_player; //private player
        //call the clear_board function
        clear_board();
    }
    else
    {
        cout<<"Error with start_game function \n";
    }
}

//mark_board
void TicTacToe::mark_board(int position)
{
    //mark vector w position -1 equal to player
    pegs[position-1] = player;
    //call set_next_player private function
    set_next_player();
}


//get_player
string TicTacToe::get_player() const
{
    return player; //player needs to be either X or O
}

//display_board
void TicTacToe::display_board() const
{
    //iterate vector of strings pegs to display 
    //a tic tac toe board in 3x3 format
    cout<<pegs[0]<<" | "<<pegs[1]<<" | "<<pegs[2]<<"\n";
    cout<<"--+---+--"<<"\n";
    cout<<pegs[3]<<" | "<<pegs[4]<<" | "<<pegs[5]<<"\n";
    cout<<"--+---+--"<<"\n";
    cout<<pegs[6]<<" | "<<pegs[7]<<" | "<<pegs[8]<<"\n";  
}


//Private functions of class Tictactoe

//set_next_player
void TicTacToe::set_next_player()
{
    //Set player. If private variable player
    // X player is O else player is X
    //using if else 
    if (player == "X")
    {
        player = "O";
    }
    else
    {
        player = "X";
    }
}

//check_board_full
bool TicTacToe::check_board_full()
{
    // return false if vector of strings pegs has available slot by checking 
    //for a “ “(space)in each element. 
    //Otherwise return true   
    //using loop
    bool board_full = true;
    for (std::size_t i = 0; i < pegs.size(); ++i)
    {
        if (pegs[i] == " ")
        {
            board_full = false;
            break;
        }
    }
    return board_full;
}


//clear_board
void TicTacToe::clear_board()
{
    for(std::size_t i = 0; i < pegs.size(); ++i){
        pegs [i] == " ";
    }
}
