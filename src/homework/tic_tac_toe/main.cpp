#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include<iostream>
#include<iomanip>
using std::cout; using std::cin;

int main() 
{
	TicTacToeManager manager;
	int o, x, t;
	string choice, again = "y";
	while(again == "y" || again == "Y")
	{
		TicTacToe game;
		//input and validation
		cout<<"Would you like to play as X or as O?\n";
		cin>>choice;
		while(!(choice == "X" || choice == "x" || choice == "O" || choice == "o"))
		{
			cout<<"That is not a valid choice, pick X or O.\n";
			cin>>choice;
		}
		if(choice == "x")
		{
			choice = "X";
		}
		else if(choice == "o")
		{
			choice = "O";
		}
		game.start_game(choice);

		//game loop
		while(game.game_over() == false)
		{
			cin>>game;
			cout<<game;
			cout<<"\n";
		}
	manager.save_game(game);
	manager.get_winner_totals(o,x,t);
	if(game.get_winner() == "C")
	{
		cout<<"Game over. It's a tie.\n";
	}
	else
		cout<<"Game over. "<<game.get_winner()<<" Has won.\n";
	cout<<std::setfill('-')<<std::setw(30)<<"-\n";
	cout<<"Winner totals\nX: "<<x<<"\nO: "<<o<<"\nTies: "<<t<<"\n";
	cout<<"Would you like to play again? Y/N: \n";
	cin>>again;
	}
	cout<<std::setfill('-')<<std::setw(30)<<"-\n";
	cout<<"Games played this session: "<<(o+t+x)<<"\n";
	cout<<"Winner totals this session:\nX: "<<x<<"\nO: "<<o<<"\nTies: "<<t<<"\n\n";
	cout<<"--Game History--\n";
	cout<<manager;
	return 0;
}