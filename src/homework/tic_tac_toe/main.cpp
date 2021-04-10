#include <iostream>
using namespace std;

#include "tic_tac_toe.h"

int main() 
{
	Game game;
	string player;
	int position;
	string again = "Y";

	while(again == "Y" || again == "y")
	{
			cout<<"Tic Tac Toe board game\n";
			cout<<"Player 1 please enter X or O to begin: ";
			cin>>player; 

		while(player != "X" || player != "O")
		{
			cout<<"You're player 1, please choose between X or O to continue: ";
			cin>>player;
			if(player == "X" || player == "O")
			{
				break;
			}

		}
	
	
		game.start_game(player);
		game.display_board();

		while(game.game_over() == false)
		{
			cout<<"Player "<<game.get_player()<<" Please input number between 1 to 9 to play. \nPlease enter '10' to close the board: ";
			cin>>position;

			while (position < 1 || position > 9)
			{
				cout<<"Please input in the position that is greater than 1 and less than 9: ";
				cin>>position;
			}
			game.mark_board(position);
			game.display_board();

		} 

		if(game.get_winner() == "C")
		{
			cout<<"Cat's Scratch!";
		}
		
		else
		cout<<"Player "<<game.get_winner()<<" has WON!\n";
		cout<<"Enter Y to play again: ";
		cin>>again;
		
	}

	return 0;
}