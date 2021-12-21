#include <iostream>
#include <vector>
#include "board.hpp"
using std::vector;
using std::cout;
using std::cin;

Board::Board(int init_size, bool init_x_turn)
{
    size = init_size;
    x_turn = init_x_turn;
    //0 for empty, 1 for x, 2 for o
    
}

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
    cout << "\n\n\n\n\n\n\n\n\n";
    for(int i = -1; i < size; i++)
    {
        for(int j = -1; j < size; j++)
        {
            if(i == -1 && j != -1)
            {
                cout << " " << j;
            }
            else if(i == -1 && j == -1)
            {
                cout << " ";
            }
            else if(i != -1 && j == -1)
            {
                cout << i << " ";
            }
            else
            {
                cout << Board::number_to_symbol(get_item_at_square(i, j)) << ' ';
            }
            if(j == size-1) 
                cout << "\n";
        }
    }

}

void Board::input_coord()
{
    int x_coord;
    int y_coord;
    cout << "Please enter an X coordinate: \n";
    cin >> x_coord;
    cout << "Please enter a Y coordinate: \n";
    cin >> y_coord;

    if(is_legal_move(x_coord, y_coord))
    {
        make_move(x_coord, y_coord);
    }
    else{
        cout << "illegal move\n";
    }

}

bool Board::is_legal_move(int const &x, int const &y)
{
    return squares[y][x] == 0;
}

void Board::make_move(int const &x, int const &y)
{
    set_item_at_square(x, y, Board::xturn_to_num(x_turn));
    switch_turn();
}

void Board::switch_turn()
{
    x_turn = !x_turn;
}

int Board::get_item_at_square(int const &x, int const &y)
{
    return squares[y][x];
}

void Board::set_item_at_square(int const &x, int const &y, int const &val)
{
    squares[y][x] = val;
}

char Board::number_to_symbol(int const &num)
{
    switch(num){
        case 0: return ' ';
        case 1: return 'x';
        case 2: return 'o';
        default: return ' ';
    }
}

int Board::xturn_to_num(bool const &xturn)
{
    if(xturn) return 1;
    else return 2;
}

bool Board::is_won()
{
    return false;
}


