//cpp

#include "tic_tac_toe.h"
#include <iostream>
using namespace std;

//Public functions of class Tictactoe
// bool TicTacToe::game_over()
// {
//     return check_board_full();
// }

//start_game
void Game::start_game(string first_player)
{
    //first_player function argument value must be X or O
    //using if else function
    player = first_player;
    this -> clear_board();
}

//mark_board
void Game::mark_board(int position)
{
    //mark vector w position -1 equal to player
    pegs[position-1] = this -> player;
    //call set_next_player private function
    this -> set_next_player();
}


//get_player
// string TicTacToe::get_player() const
// {
//     return player; //player needs to be either X or O
// }

//display_board
void Game::display_board() const
{
    //iterate vector of strings pegs to display 
    //a tic tac toe board in 3x3 format
    for (int i = 0; i < 9; ++i)
    {
        cout<< i + 1;
        cout<<" "<<pegs[i];
        cout<<"_____"<<" |";
        if((i + 1) % 3 == 0)
        {
            cout<< "\n";
        }
    }
}


//Private functions of class Tictactoe

//set_next_player
void Game::set_next_player()
{
    //Set player. If private variable player
    // X player is O else player is X
    //using if else 
    if (player == "X")
    {
        player = 'O';
    }
    else
    {
        player = "X";
    }
}

//check_board_full
bool Game::check_board_full()
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
void Game::clear_board()
{
    for(std::size_t i = 0; i < pegs.size(); ++i){
        pegs [i] == " ";
    }
}

//set_winner
void Game::set_winner()
{
    if (player == "O")
    {
        winner = "X";
    }
    else 
    {
        winner = "O";
    }
}


//game_over
bool Game::game_over()
{
    //check win with column
    bool column_winner = this -> check_column_win();
    //check win with row
    bool row_winner = this -> check_row_win();
    //check win with diagonal
    bool diagonal_winner = this -> check_diagonal_win();
    // check to see if board is full
    bool is_full = this -> check_board_full();

    if(column_winner or row_winner or diagonal_winner)
    {
        this -> set_winner();
        return true;
    }

    if(column_winner && row_winner && diagonal_winner && is_full)
    {
        winner = "C";
        return true;
    }

    return false;
}


//check_diagonal_win; 2 diagonal lines; 2 possibilities
bool Game::check_diagonal_win()
{
    bool win = false;

    //for Xs
    if (pegs[0] == "X" && pegs[4] == "X" && pegs[8] == "X")
    {
        win = true;
        return win;
    }
    if (pegs[0] == "O" && pegs[4] == "O" && pegs[8] == "O")
    {
        win = true;
        return win;
    }

    //for Os
    if (pegs[2] == "X" && pegs[4] == "X" && pegs[6] == "X")
    {
        win = true;
        return win;
    }
    if (pegs[2] == "O" && pegs[4] == "O" && pegs[6] == "O")
    {
        win = true;
        return win;
    }

    return win;
}


//check_column_win; 3 columns total; 3 possibilities
bool Game::check_column_win()
{
    bool win = false;

    //case 1
    if (pegs[0] == "X" && pegs[3] == "X" && pegs[6] == "X")
    {
        win = true;
        return win;
    }
    if (pegs[0] == "O" && pegs[3] == "O" && pegs[6] == "O")
    {
        win = true;
        return win;
    }


    //case 2
    if (pegs[1] == "X" && pegs[4] == "X" && pegs[7] == "X")
    {
        win = true;
        return win;
    }
     if (pegs[1] == "O" && pegs[4] == "O" && pegs[7] == "O")
    {
        win = true;
        return win;
    }


    //case 3
    if (pegs[2] == "X" && pegs[5] == "X" && pegs[8] == "X")
    {
        win = true;
        return win;
    }
    if (pegs[2] == "O" && pegs[5] == "O" && pegs[8] == "O")
    {
        win = true;
        return win;
    }
    
    return win;
}


//check_row_win; 3 row lines, 3 possibilities
bool Game::check_row_win()
{
    bool win = false;

    //case 1
    if (pegs[0] == "X" && pegs[1] == "X" && pegs[2] == "X")
    {
        win = true;
        return win;
    }
    if (pegs[0] == "O" && pegs[1] == "O" && pegs[2] == "O")
    {
        win = true;
        return win;
    }
    

    //case 2
    if (pegs[3] == "X" && pegs[4] == "X" && pegs[5] == "X")
    {
        win = true;
        return win;
    }
    if (pegs[3] == "O" && pegs[4] == "O" && pegs[5] == "O")
    {
        win = true;
        return win;
    }

    //case 3
    if (pegs[6] == "X" && pegs[7] == "X" && pegs[8] == "X")
    {
        win = true;
        return win;
    }
    if (pegs[6] == "O" && pegs[7] == "O" && pegs[8] == "O")
    {
        win = true;
        return win;
    }
    return win;
}