#include<memory>
using std::unique_ptr; using std::make_unique;

#include <string>
using std::string;

#include "tic_tac_toe.h"
#include "tic_tac_toe_manager.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"

string go_again;

int main() 
{
  
  
  TicTacToeManager manager;  //Must be outside the looping game fcn, b/c this keeps track of all the games
  
  int x;  //Local variables for use with get_winner_total
  int o;
  int t;

  do  //Each game
  {
  
    unique_ptr<TicTacToe> game;//Just reserves space in memory

    string game_type;
    
    

    do
    {
      cout<<"Would you like to play 3x3 or 4x4 TTT? Type '3' or '4': \n";
      cin>>game_type;

      if(game_type == "3")
      {
        game = make_unique<TicTacToe3>();
      }
      else if(game_type == "4")
      {
        game = make_unique<TicTacToe4>();
      }
    }
    while(!(game_type == "3" || game_type == "4")); //Input validation: first_player input to be 3 or 4

    



    //Now we may use game->
    //With pointers, we have to use save(*game) for saving game to manager. It is so that C++ knoews we want to work with the //value

    string first_player;

    do
    {
      cout<<"Please enter first player. (Enter X or O): \n";
      cin>> first_player;

      if (first_player == "x")
      {
        first_player = "X";
      }
      else if (first_player == "o")
      {
        first_player = "O";
      }
    }
    while(!(first_player == "X" || first_player == "O")); //Input validation: first_player input to be X or O

    game->start_game(first_player);

    cout<<*game; //Origianal display of board

    do
    {
      cin>>*game;

      cout<<*game; //This displays board (short/neat code in main)
    }
    while(!(game->game_over()));
    
    //At the end of every game:
    
  
    cout<<"GAME OVER. The winner was: " << game->get_winner() << "\n";

    manager.save_game(game); //Saves current game to the manager (adds TicTacToe game instance to the TicTacToeManager vector)
    
    //Display the running scores (for X, O, and ties) Ex: X wins 1, O wins 5, ties 11.
    manager.get_winner_total(o, x, t); //Fcn updates o, x, and t to the correct values
    cout<<"Games Winning Tally: \n";
    cout<<"O wins: " << o << "\n";
    cout<<"X wins: " << x << "\n";
    cout<<"Ties: " << t << "\n";
    
    cout<<"Would you like to play again? Type 'Y' or 'y' to play again. \n";
    cin>>go_again;

    
  }
  while(go_again == "Y" || go_again == "y");
	
  cout<<"-------------------------------------------------------------------- \n";
  cout<<"Displaying game boards history: \n";
  cout<<manager; //Displays games history

  //Display the final/running scores
  manager.get_winner_total(o, x, t); //Fcn updates o, x, and t to the correct values
  cout<<"Final Games Winning Tally: \n";
  cout<<"O wins: " << o << "\n";
  cout<<"X wins: " << x << "\n";
  cout<<"Ties: " << t << "\n\n";

  cout<<"Thanks for playing the Tic Tac Toe game. \nPlease leave a 5 star review on the app store. \n";
    
  return 0;
}