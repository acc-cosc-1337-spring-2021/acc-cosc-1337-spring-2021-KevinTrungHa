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
  vector<string> pegs;  //Don't initialize this anymore. It is initialized with constructor
  virtual bool check_column_win();  //Make these 3 fcn "protected virtual functions." Does that mean final? or ()=0 ?
  virtual bool check_row_win();
  virtual bool check_diagonal_win();

public: //Access Specifier
  //Constructors:
  TicTacToe(){} //Default synthesized constructor;  FIX BOTH OF THESE
  TicTacToe(int size) : pegs(size*size, " "){}//Initializes 9 or 16 elements depending on input
  
  bool game_over(); //Account for someone winning on the 9th mark.
  void start_game(string first_player);
  void mark_board(int position);
  string get_player() const; //const means fcn can only read; it cannot write
  // Removed void display_board() const; & replaced w/ ostream aperator <<(cout)  
  string get_winner() const;

  //Friend FCNS:
  // New operator overloading FCNs (overloading cout & cin)
  friend std::ostream& operator<<(std::ostream& out, const TicTacToe& game);  //FIX Overload these for 4x4 grid
  friend std::istream& operator>>(std::istream& in, TicTacToe& game);


private:

  void set_winner();  //Maybe public now?
  
  void set_next_player();
  bool check_board_full();
  void clear_board();

 //Class private data
  string player;
  string winner;

};

#endif