#include <iostream>
#include "board.hpp"

using std::cout;

int main()
{
    Board mainboard(3, true);
    cout << mainboard.get_item_at_square(0, 1) << "\n";
    /*while(!mainboard.is_won())
    {
        mainboard.display_board();
        mainboard.input_coord();
    }*/
}