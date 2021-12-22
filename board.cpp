#include <iostream>
#include <vector>
#include "board.hpp"
using std::vector;
using std::cout;
using std::cin;

//0 for empty, 1 for x, 2 for o
Board::Board(int init_size, bool init_x_turn): squares(std::vector(init_size, std::vector<int>(init_size, 0)))
{
    size = init_size;
    x_turn = init_x_turn;
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

int Board::enter_size()
{
    int temp_size;
    try
    {
        cout << "Enter board dimension (2 - 10)\n";
        cin >> temp_size;
        if(temp_size < 2 || temp_size > 10)
        {
            cout << "Invalid size\n";
            return enter_size();
        }
        else
        {
            return temp_size;
        }
    }
    catch(const char* e){
        cout << "Invalid size\n";
        return enter_size();
    }

}

void Board::display_board(bool wasIllegal)
{
    cout << "\n\n\n\n\n\n\n\n\n";
    if(wasIllegal)
    {
        cout << "Illegal move, try again\n";
    }
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
                cout << Board::number_to_symbol(get_item_at_square(j, i)) << ' ';
            }
            if(j == size-1) 
                cout << "\n";
        }
    }
}

void Board::display_board()
{
    display_board(false);
}

//return 0 for sucessful, 1 for error
int Board::input_coord()
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
        return 0;
    }
    else
    {
        return 1;
    }

}

void Board::switch_turn()
{
    x_turn = !x_turn;
}

bool Board::is_x_turn()
{
    return x_turn;
}

int Board::get_size()
{
    return size;
}

bool Board::is_won()
{
    return false;
}

bool Board::is_legal_move(int const &x, int const &y)
{
    if(x < size && y < size) return squares[y][x] == 0;
    else return false;
}

void Board::make_move(int const &x, int const &y)
{
    set_item_at_square(x, y, Board::xturn_to_num(x_turn));
    switch_turn();
}


int Board::get_item_at_square(int const &x, int const &y)
{
    return squares[y][x];
}

void Board::set_item_at_square(int const &x, int const &y, int const &val)
{
    squares[y][x] = val;
}
