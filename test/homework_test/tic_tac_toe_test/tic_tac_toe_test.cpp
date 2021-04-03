#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "tic_tac_toe.h"
#include <iostream>
using std::cout;
using std::cin;

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}


TEST_CASE("Test functions start_game, mark_board, game_over functions, also tie case")

{
  TicTacToe test_game;

  test_game.start_game("X");  //X is first player

  test_game.mark_board(1);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(2);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(3);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(5);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(4);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(6);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(8);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(7);
  REQUIRE(test_game.game_over() == false);
  test_game.mark_board(9);
  REQUIRE(test_game.game_over() == true); 
  //game over with after being full 9 squares
}