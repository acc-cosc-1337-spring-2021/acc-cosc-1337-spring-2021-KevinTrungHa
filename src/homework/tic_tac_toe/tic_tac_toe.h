//h

#include <string>
using std::string;

#include <vector>
using std::vector;

//set up class for tic tac toe game
class Game
{   
    //public functions of class Tictactoe
    public:

        bool game_over();
        void start_game(string first_player);
        void mark_board(int position);
        string get_player() const{return player;}
        void display_board() const;
        string get_winner(){return winner;}

    //private functions of class Tictactoe
    private:

        void set_next_player();
        bool check_board_full();
        void clear_board();
        bool check_column_win();
        bool check_row_win();
        bool check_diagonal_win();
        void set_winner();

        //class private data
        vector<string> pegs{9, " "}; //initialize to 9 spaces
        string player, winner;
};