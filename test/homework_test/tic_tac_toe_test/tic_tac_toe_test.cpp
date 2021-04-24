#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "tic_tac_toe.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include "tic_tac_toe_manager.h"

#include <iostream>
using std::cout; using std::cin;

#include <memory>
using std::unique_ptr; using std::make_unique;

//For test cases, initialize like this:
// unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
//or use <TicTacToe4> for 4x4 grid


TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Test TicTacToe start_game, mark_board, and game_over fcns", "Game ends in tie")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();

  game1->start_game("X");  //X is first player

  game1->mark_board(1);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(2);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(3);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(5);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(4);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(6);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(8);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(7);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(9);
  REQUIRE(game1->game_over() == true);

  //After all 9 slots are selected:
  REQUIRE(game1->get_winner() == "C"); //Check string winner is C by running public get_winner fcn

  manager.save_game(game1); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 0);
  REQUIRE(t == 1);
}




TEST_CASE("Test first player set to X")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("O");  //O is first player

  REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(1);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(4);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(7);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);

}

TEST_CASE("Test win by second column")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(2);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(1);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(6);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(5);
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == false);
  game->mark_board(8);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by third column")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(3);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(6);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(5);
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by first row")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(1);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(7);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by second row")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(4);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(5);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(6);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by third row")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(7);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(5);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(8);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win diagonally from top left")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(1);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(5);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win diagonally from bottom left")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe3>();
  game->start_game("X");  //X is first player

  game->mark_board(7);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(5);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test TicTacToe manager")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;

  manager.get_winner_total(o, x, t);  //They should all be at 0 at the start of the game
  REQUIRE(o == 0);
  REQUIRE(x == 0);
  REQUIRE(t == 0);

  //Game 1: (X wins)
  unique_ptr<TicTacToe> game1 = make_unique<TicTacToe3>();
  game1->start_game("X");
  
  game1->mark_board(4);  //X move
  REQUIRE(game1->game_over() == false);
  game1->mark_board(2);  //O move
  REQUIRE(game1->game_over() == false);
  game1->mark_board(5);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(3);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(6);
  REQUIRE(game1->game_over() == true);
  REQUIRE(game1->get_winner() == "X");

  manager.save_game(game1); //Saves game 1 to manager vector

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);

  //Game 2: (O Wins)
  unique_ptr<TicTacToe> game2 = make_unique<TicTacToe3>();
  game2->start_game("O");

  game2->mark_board(7);  //O move
  REQUIRE(game2->game_over() == false);
  game2->mark_board(2);  //X move
  REQUIRE(game2->game_over() == false);
  game2->mark_board(8);
  REQUIRE(game2->game_over() == false);
  game2->mark_board(3);
  REQUIRE(game2->game_over() == false);
  game2->mark_board(9);
  REQUIRE(game2->game_over() == true);
  REQUIRE(game2->get_winner() == "O");

  manager.save_game(game2); //Saves game 2 to manager vector

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 1);
  REQUIRE(x == 1);
  REQUIRE(t == 0);

  //Game 3: (Tie)
  unique_ptr<TicTacToe> game3 = make_unique<TicTacToe3>();
  game3->start_game("X"); //X is first player

  game3->mark_board(1);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(2);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(3);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(5);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(4);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(6);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(8);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(7);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(9);
  REQUIRE(game3->game_over() == true);

  manager.save_game(game3); //Saves game 3 to manager vector

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 1);
  REQUIRE(x == 1);
  REQUIRE(t == 1);

}




  


















//4x4 Test Cases

TEST_CASE("Test TicTacToe start_game, mark_board, and game_over fcns 4", "Game ends in tie")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();

  game->start_game("X");  //X is first player

  game->mark_board(1);
  REQUIRE(game->game_over() == false);
  game->mark_board(2);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(5);
  REQUIRE(game->game_over() == false);
  game->mark_board(4);
  REQUIRE(game->game_over() == false);
  game->mark_board(6);
  REQUIRE(game->game_over() == false);
  game->mark_board(8);
  REQUIRE(game->game_over() == false);
  game->mark_board(7);
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == false);
  game->mark_board(10);
  REQUIRE(game->game_over() == false);
  game->mark_board(11);
  REQUIRE(game->game_over() == false);
  game->mark_board(12);
  REQUIRE(game->game_over() == false);
  game->mark_board(14);
  REQUIRE(game->game_over() == false);
  game->mark_board(13);
  REQUIRE(game->game_over() == false);
  game->mark_board(16);
  REQUIRE(game->game_over() == false);
  game->mark_board(15);
  REQUIRE(game->game_over() == true);


  //After all 9 slots are selected:
  REQUIRE(game->get_winner() == "C"); //Check string winner is C by running public get_winner fcn

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 0);
  REQUIRE(t == 1);
}

TEST_CASE("Test first player set to X 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  REQUIRE(game->get_player() == "X");
}

TEST_CASE("Test first player set to O 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("O");  //O is first player

  REQUIRE(game->get_player() == "O");
}

TEST_CASE("Test win by first column 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(1);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(5);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(6);
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == false);
  game->mark_board(10);
  REQUIRE(game->game_over() == false);
  game->mark_board(13);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);

}

TEST_CASE("Test win by second column 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(2);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(6);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(7);
  REQUIRE(game->game_over() == false);
  game->mark_board(10);
  REQUIRE(game->game_over() == false);
  game->mark_board(11);
  REQUIRE(game->game_over() == false);
  game->mark_board(14);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by third column 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(3);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(4);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(7);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(8);
  REQUIRE(game->game_over() == false);
  game->mark_board(11);
  REQUIRE(game->game_over() == false);
  game->mark_board(12);
  REQUIRE(game->game_over() == false);
  game->mark_board(15);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by fourth column 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(4);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(8);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(7);
  REQUIRE(game->game_over() == false);
  game->mark_board(12);
  REQUIRE(game->game_over() == false);
  game->mark_board(11);
  REQUIRE(game->game_over() == false);
  game->mark_board(16);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by first row 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(1);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(7);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(8);
  REQUIRE(game->game_over() == false);
  game->mark_board(4);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by second row 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(5);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(1);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(6);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);
  REQUIRE(game->game_over() == false);
  game->mark_board(7);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(8);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by third row 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(9);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(1);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(10);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);
  REQUIRE(game->game_over() == false);
  game->mark_board(11);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(12);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win by fourth row 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(13);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(1);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(14);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);
  REQUIRE(game->game_over() == false);
  game->mark_board(15);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(16);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");
  
  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win diagonally from top left 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(1);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(6);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(11);
  REQUIRE(game->game_over() == false);
  game->mark_board(12);
  REQUIRE(game->game_over() == false);
  game->mark_board(16);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}

TEST_CASE("Test win diagonally from bottom left 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;
  
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");  //X is first player

  game->mark_board(13);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);  //O move
  REQUIRE(game->game_over() == false);
  game->mark_board(10);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(7);
  REQUIRE(game->game_over() == false);
  game->mark_board(12);
  REQUIRE(game->game_over() == false);
  game->mark_board(4);
  REQUIRE(game->game_over() == true);
  REQUIRE(game->get_winner() == "X");

  manager.save_game(game); //Saves game 3 to manager vector
  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
}


TEST_CASE("Test TicTacToe manager 4")
{
  TicTacToeManager manager;

  int x = 0;  //Local variables for use with get_winner_total
  int o = 0;
  int t = 0;

  
  manager.get_winner_total(o, x, t);  //They should all be at 0 at the start of the game
  REQUIRE(o == 0);
  REQUIRE(x == 0);
  REQUIRE(t == 0);
  

  //Game 1: (X wins)
  unique_ptr<TicTacToe> game1 = make_unique<TicTacToe4>();
  game1->start_game("X");
  
  game1->mark_board(1);  //X move
  REQUIRE(game1->game_over() == false);
  game1->mark_board(5);  //O move
  REQUIRE(game1->game_over() == false);
  game1->mark_board(2);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(6);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(3);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(7);
  REQUIRE(game1->game_over() == false);
  game1->mark_board(4);
  REQUIRE(game1->game_over() == true);
  REQUIRE(game1->get_winner() == "X");

  
  manager.save_game(game1); //Saves game 1 to manager vector

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 0);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
  

  //Game 2: (O Wins)
  unique_ptr<TicTacToe> game2 = make_unique<TicTacToe4>();
  game2->start_game("O");

  game2->mark_board(1);  //O move
  REQUIRE(game2->game_over() == false);
  game2->mark_board(5);  //X move
  REQUIRE(game2->game_over() == false);
  game2->mark_board(2);
  REQUIRE(game2->game_over() == false);
  game2->mark_board(6);
  REQUIRE(game2->game_over() == false);
  game2->mark_board(3);
  REQUIRE(game2->game_over() == false);
  game2->mark_board(7);
  REQUIRE(game2->game_over() == false);
  game2->mark_board(4);
  REQUIRE(game2->game_over() == true);
  REQUIRE(game2->get_winner() == "O");

  
  manager.save_game(game2); //Saves game 2 to manager vector

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 1);
  REQUIRE(x == 1);
  REQUIRE(t == 0);
  

  //Game 3: (Tie)
  unique_ptr<TicTacToe> game3 = make_unique<TicTacToe4>();
  game3->start_game("X"); //X is first player

  game3->mark_board(1);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(2);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(3);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(4);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(5);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(6);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(7);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(8);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(9);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(10);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(11);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(12);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(14);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(15);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(16);
  REQUIRE(game3->game_over() == false);
  game3->mark_board(13);
  REQUIRE(game3->game_over() == true);
  
  manager.save_game(game3); //Saves game 3 to manager vector

  manager.get_winner_total(o, x, t);
  REQUIRE(o == 1);
  REQUIRE(x == 1);
  REQUIRE(t == 1);
  
}


TEST_CASE("Test TicTacToe filling more than 9 slots 4")
{
  unique_ptr<TicTacToe> game = make_unique<TicTacToe4>();
  game->start_game("X");

  game->mark_board(1);  //X move
  REQUIRE(game->game_over() == false);
  game->mark_board(2);
  REQUIRE(game->game_over() == false);
  game->mark_board(3);
  REQUIRE(game->game_over() == false);
  game->mark_board(4);
  REQUIRE(game->game_over() == false);
  game->mark_board(5);
  REQUIRE(game->game_over() == false);
  game->mark_board(7);
  REQUIRE(game->game_over() == false);
  game->mark_board(6);
  REQUIRE(game->game_over() == false);
  game->mark_board(9);
  REQUIRE(game->game_over() == false);
  game->mark_board(8);
  REQUIRE(game->game_over() == false);
  game->mark_board(10);
  REQUIRE(game->game_over() == false);

}