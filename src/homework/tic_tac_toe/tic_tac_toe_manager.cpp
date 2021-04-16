//cpp

#include "tic_tac_toe_manager.h"
#include<iostream>
using std::cout;

//friend overload printing vector of games
std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager)
{
    for(int i = 0; i <= manager.games.size(); i++)
    {
        cout<<manager.games[i];
        cout<<"\n";
    }

    return out;
}
//winner incrementor
void TicTacToeManager::update_winner_count(std::string winner)
{
    if(winner == "X")
    {
        x_wins++;
    }
    else if(winner == "O")
    {
        o_wins++;
    }
    else
    {
        ties++;
    }
    
}

//saves tictactoe object to vector and updates winner count
void TicTacToeManager::save_game(TicTacToe game)
{
    games.push_back(game);
    update_winner_count(game.get_winner());
}

//sets reference variables equal to private class variables, cheats them out
void TicTacToeManager::get_winner_totals(int& o, int& x, int& t)
{
    o = o_wins;
    x = x_wins;
    t = ties;
}