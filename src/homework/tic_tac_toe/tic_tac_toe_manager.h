#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H

#include "tic_tac_toe.h"
#include "tic_tac_toe_data.h"

#include <vector>

#include <memory>
using std::unique_ptr; using std::make_unique;


class TicTacToeManager
{
public:
  //Consstructor:
  TicTacToeManager() = default;
  TicTacToeManager(TicTacToeData d);  
  //Destructor:
  ~TicTacToeManager();
  
  void save_game(unique_ptr<TicTacToe>& b);  
  friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager); 
  void get_winner_total(int& o, int& x, int&t);


private:
  void update_winner_count(string winner);
  
  std::vector<unique_ptr<TicTacToe>> games;  
  int x_win = {0};
  int o_win = {0};
  int ties = {0};
  TicTacToeData data;  

};

#endif