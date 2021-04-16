//h
#ifndef TIC_TAC_TOE_MANAGER_H
#define TIC_TAC_TOE_MANAGER_H
#include "tic_tac_toe.h"

class TicTacToeManager
{
friend std::ostream& operator<<(std::ostream& out, const TicTacToeManager& manager);

public:
    void get_winner_totals(int& o, int& x, int& t);
    void save_game(TicTacToe game);

private:
    void update_winner_count(std::string winner);
    vector<TicTacToe> games;
    int o_wins{0}, x_wins{0}, ties{0};
};


#endif