#include <vector>
using std::vector;

class Board
{
private:
    int size;
    bool x_turn;
    vector<vector<int>> squares;

public:
    Board(int init_size, bool x_turn);
    bool is_x_turn();
    int get_size();
    void display_board();
    void input_coord();
    int get_item_at_square(int x, int y);

};