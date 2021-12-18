#include <iostream>
#include "board.cpp"

using std::cout;

int main()
{
    Board mainboard(3, true);
    while(!mainboard.is_won())
    {
        mainboard.display_board();
        mainboard.input_coord();
        cout << mainboard.is_won();
    }
}