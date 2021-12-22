#include <iostream>
#include "board.hpp"

using std::cout;

int main()
{
    int board_size = Board::enter_size();
    Board mainboard(board_size, true);
    
    while(!mainboard.is_won())
    {
        mainboard.display_board();
        //runs input_coord until it is successful, if unsucessful, will redo the display with error message argument
        while(mainboard.input_coord() != 0){
            mainboard.display_board(true);
        }

    }
}