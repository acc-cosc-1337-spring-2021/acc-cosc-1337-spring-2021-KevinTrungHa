#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <iostream>
using std::cout;   using std::cin;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include<memory>
using std::unique_ptr; using std::make_unique;



class TicTacToe
{

protected:
  vector<string> pegs;  
  virtual bool check_column_win();  
  virtual bool check_row_win();
  virtual bool check_diagonal_win();

public: 
  //Constructors:
  TicTacToe(vector <string> p, string win) : pegs(p), winner(win){} 
  TicTacToe(){} 
  TicTacToe(int size) : pegs(size*size, " "){}
  
  vector<string> get_pegs() const {return pegs;} 
  bool game_over(); 
  void start_game(string first_player);
  void mark_board(int position);
  string get_player() const; 
  string get_winner() const;


  friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game); 
  friend std::istream& operator>>(std::istream& in, TicTacToe& game);


private:

  void set_winner(); 
  
  void set_next_player();
  bool check_board_full();
  void clear_board();


  string player;
  string winner;

};

#endif