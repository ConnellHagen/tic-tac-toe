#include <iostream>
#include "board.hpp"

using std::cout;

int main()
{
    //setup
    int board_size = Board::enter_size();
    Board mainboard(board_size, true);

    //game loop
    while(mainboard.winner() == 0)
    {
        mainboard.display_board();
        //runs input_coord until it is successfully executed. if unsucessful, will redo the display with error message argument before restarting
        while(mainboard.input_coord() != 0){
            Board::print_blank();
            mainboard.display_board(true);
        }

    }

    //post game message
    mainboard.display_win_message();

    return 0;
}