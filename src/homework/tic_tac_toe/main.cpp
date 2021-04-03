#include <iostream>
using namespace std;

#include "tic_tac_toe.h"

char play_again;

int main() 
{
	TicTacToe game;
	string player;
	int position;

	cout<<"Tic Tac Toe board game\n";
	cout<<"Player 1 please enter X or O to begin: ";
	cin>>player;

	game.start_game(player);
	game.display_board();

	do
	{
		cout<<"Player "<<game.get_player()<<" Please input number between 1 to 9 to play. \nPlease enter '10' to close the board: ";
		cin>>position;
		game.mark_board(position);
		game.display_board();

	} while(position != 10);
	return 0;
}