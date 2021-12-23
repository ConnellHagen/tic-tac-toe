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

int Board::symbol_to_number(char const &symbol)
{
    switch(symbol)
    {
        case ' ': return 0;
        case 'x': return 1;
        case 'o': return 2;
        default: return 3;
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

void Board::print_blank()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
}

void Board::display_board(bool const &wasIllegal)
{
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

//0 for no winner, 1 for x, 2 for o, 3 for cat's game.
int Board::winner()
{
    bool all_filled_squares = true;

    //checking vertical line wins
    for(int i = 0; i < size; i++)
    {
        char first_square;
        for(int j = 0; j < size; j++)
        {
            if(get_item_at_square(i, j) == 0)
            {
                all_filled_squares = false;
                break;
            }
            if(j == 0) first_square = get_item_at_square(i, j);
            else if(get_item_at_square(i, j) != first_square) break;
            if(j == size - 1) return Board::symbol_to_number(first_square);
        }
    }

    //checking horizontal line wins
    for(int j = 0; j < size; j++)
    {
        char first_square;
        for(int i = 0; i < size; i++)
        {
            if(get_item_at_square(i, j) == 0)
            {
                all_filled_squares = false;
                break;
            }
            if(i == 0) first_square = get_item_at_square(i, j);
            else if(get_item_at_square(i, j) != first_square) break;
            if(i == size - 1) return Board::symbol_to_number(first_square);
        }
    }

    //checking diagonal line wins
    for(int i = 0; i <= 1; i++)
    {
        char first_square;
        for(int j = 0; j < size; j++)
        {   
            if(i == 0)
            {
                if(get_item_at_square(j, j) == 0)
                {
                    all_filled_squares = false;
                    break;
                }
                if(j == 0) first_square = get_item_at_square(j, j);
                else if(get_item_at_square(j, j) != first_square) break;
                if(j == size - 1) return Board::symbol_to_number(first_square);
            }
            else
            {
                if(get_item_at_square(size - j - 1, j) == 0)
                {
                    all_filled_squares = false;
                    break;
                }
                if(j == 0) first_square = get_item_at_square(size - 1, j);
                else if(get_item_at_square(size - j - 1, j) != first_square) break;
                if(j == size - 1) return Board::symbol_to_number(first_square);
            }
            
        }
    }

    //cat's game / draw
    if(all_filled_squares) return 3;

    //default return (no winner)
    return 0;
}

void Board::display_win_message()
{
    Board::print_blank();
    display_board();
    int the_winner = winner();
    switch(the_winner)
    {
        case 0: cout << "Nobody has won the game... somehow...\n"; break;
        case 1: cout << "Player X has won the game!\n"; break;
        case 2: cout << "Player O has won the game!\n"; break;
        case 3: cout << "It's a cat's game!"; break;
    }
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
