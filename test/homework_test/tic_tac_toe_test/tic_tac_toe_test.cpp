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
  Game test_game;

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


TEST_CASE("Test the 'start_game' function: Player 'X")
{
	Game game;
	game.start_game("X");
	REQUIRE(game.get_player() == "X");
}

TEST_CASE("Test the 'start_game' function: Player 'O'")
{
	Game game;
	game.start_game("O");
	REQUIRE(game.get_player() == "O");
}

TEST_CASE("Test the 'check_diagonal_win' function: Starting from position 1 down to position 9, through position 5")
{
	Game game;

	game.start_game("X");
	game.mark_board(1); //X
	game.mark_board(2); //O
	game.mark_board(5); //X
	game.mark_board(4); //O
	game.mark_board(9); //X
	
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test the 'check_diagonal_win' function: Starting from position 7 up to position 3, through position 5")
{
	Game game;

	game.start_game("X");
	game.mark_board(7); //X
	game.mark_board(2); //O
	game.mark_board(5); //X
	game.mark_board(4); //O
	game.mark_board(3); //X
	
	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test 'check_column_win' function: Starting from position 1 down to 7, through 4")
{
	Game game;
	game.start_game("X");
	game.mark_board(1); //X
	game.mark_board(2);	//O
	game.mark_board(4); //X
	game.mark_board(3); //O
	game.mark_board(7); //X

	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test 'check_column_win' function: Starting from position 2 down to 8, through 5")
{
	Game game;
	game.start_game("X");
	game.mark_board(2); //X
	game.mark_board(1); //O
	game.mark_board(5); //X
	game.mark_board(3); //O
	game.mark_board(8); //X

	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test 'check_column_win' function: Starting from position 3 down to 9, through 6")
{
	Game game;
	game.start_game("X");
	game.mark_board(3); //X
	game.mark_board(1);	//O
	game.mark_board(6); //X
	game.mark_board(4); //O
	game.mark_board(9); //X

	REQUIRE(game.game_over() == true);
}
TEST_CASE("Test 'check_row_win' function: Starting from position 1 to 3, through 2")
{
	Game game;
	game.start_game("X");
	game.mark_board(1); //X
	game.mark_board(4); //O
	game.mark_board(3); //X
	game.mark_board(7); //O
	game.mark_board(2); //X

	REQUIRE(game.game_over() == true);
}


TEST_CASE("Test 'check_row_win' function: Starting from position 4 to 6, through 5")
{
	Game game;
	game.start_game("X");
	game.mark_board(4); //X
	game.mark_board(3); //O
	game.mark_board(5); //X
	game.mark_board(8); //O
	game.mark_board(6); //X

	REQUIRE(game.game_over() == true);
}

TEST_CASE("Test 'check_row_win' function: Starting from position 7 to 9, through 8")
{
	Game game;
	game.start_game("X");
	game.mark_board(7); //X
	game.mark_board(4); //O
	game.mark_board(8); //X
	game.mark_board(1); //O
	game.mark_board(9); //X

	REQUIRE(game.game_over() == true);
}