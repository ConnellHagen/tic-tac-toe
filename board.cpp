#include <iostream>
#include <vector>
#include "board.hpp"
using std::vector;
using std::cout;
using std::cin;

bool Board::is_x_turn()
{
    return x_turn;
}

int Board::get_size()
{
    return size;
}

void Board::display_board()
{
    cout << "\n\n\n";
    cout << "  0 1 2\n";
    cout << "0 x x x\n";
    //cout << "_____\n";
    cout << "1 x x x\n";
    //cout << "_____\n";
    cout << "2 x x x\n";
}

void Board::input_coord()
{
    int x_coord;
    int y_coord;
    cout << "Please enter an X coordinate: \n";
    cin >> x_coord;
    cout << "Please enter a Y coordinate: \n";
    cin >> y_coord;
}

int Board::get_item_at_square(int x, int y)
{
    return squares[y][x];
}

Board::Board(int init_size, bool init_x_turn)
{
    size = init_size;
    x_turn = init_x_turn;
    vector<vector<int>> squares(size, vector<int>(size, 0));
    //0 for empty, 1 for x, 2 for o
}
