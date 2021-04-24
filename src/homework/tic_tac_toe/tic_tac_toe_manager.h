#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"

#include <vector>

#include <memory>
using std::unique_ptr; using std::make_unique;


class TicTacToeManager
{
public:
  void save_game(unique_ptr<TicTacToe>& b);  //Change TTT param to a unique_ptr of TTT reference
  friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager); //Overloaded fcn
  
  void get_winner_total(int& o, int& x, int&t);


private:
  void update_winner_count(string winner);
  
  std::vector<unique_ptr<TicTacToe>> games;  // vector of TicTacToe games //THIS MAY CHANGE A LOT OF THINGS
  int x_win = {0};
  int o_win = {0};
  int ties = {0};

};

#endif