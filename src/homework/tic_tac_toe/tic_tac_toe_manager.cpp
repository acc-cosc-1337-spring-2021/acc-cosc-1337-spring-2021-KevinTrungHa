//cpp


#include "tic_tac_toe_manager.h"

#include <iostream>
using std::cin; using std::cout;

#include<vector>
using std::vector;


TicTacToeManager::TicTacToeManager(TicTacToeData d) : data{d}  
{
  games = data.get_games();  

  for(auto& game : games)
  {
    update_winner_count(game->get_winner());
  }
}


TicTacToeManager::~TicTacToeManager()
{
  cout<<"\n Saving games... \n";
  data.save_games(games);  
}

//Public fcns
void TicTacToeManager::save_game(unique_ptr<TicTacToe>& b)
{
  update_winner_count(b->get_winner());
  
  games.push_back(std::move(b)); 
  
}

std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager) //Friend fcn
{
  
  for(auto& game: manager.games)
  {
    out<<*game; 
    out<<"\n";
  }

  return out;
}
  
void TicTacToeManager::get_winner_total(int& o, int& x, int&t) 
{
  
  o = o_win;
  x = x_win;
  t = ties;
}


void TicTacToeManager::update_winner_count(string winner)
{
  if(winner == "X")
  {
    x_win += 1;
  }
  else if(winner == "O")
  {
    o_win += 1;
  }
  else
  {
    ties += 1;
  }
}

