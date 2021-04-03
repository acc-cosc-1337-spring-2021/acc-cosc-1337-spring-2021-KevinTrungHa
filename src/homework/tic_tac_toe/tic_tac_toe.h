//h

#include <string>
using std::string;

#include <vector>
using std::vector;

//set up class for tic tac toe game
class TicTacToe
{   
    //public functions of class Tictactoe
    public:
        bool game_over()
        {
            return this ->check_board_full();
        }
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const{return player;}
        void display_board() const;

    //private functions of class Tictactoe
    private:
        void set_next_player();
        bool check_board_full();
        void clear_board();

        //class private data
        string player;
        vector<string> pegs{9, " "}; //initialize to 9 spaces
    
};