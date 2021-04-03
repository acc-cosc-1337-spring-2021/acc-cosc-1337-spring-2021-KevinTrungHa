#include <iostream>
using std::cout;
using std::cin;

#include "tic_tac_toe.h"

char play_again;

int main() 
{
	TicTacToe game;
	string first_player;

	cout<<"Please enter either X or O as first player: \n";
	cin>>first_player;

	game.start_game(first_player);

	do

	{
		int position;
		cout<<"Please enter a position between 1 to 9: \n";
		cin>>position;

		game.mark_board(position);

		cout<<"Please input Y or y to play again: \n";
		cin>>play_again;
	}
	while (play_again == 'Y' || play_again == 'y');

	cout<<"Thanks for playing Tic Tac Toe game!";

		return 0;
}