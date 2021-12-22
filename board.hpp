#include <vector>

class Board
{
private:
    int size;
    bool x_turn;
    std::vector<std::vector<int>> squares{};

    static char number_to_symbol(int const &num);
    static int xturn_to_num(bool const &xturn);

public:
    Board(int init_size, bool x_turn);

    static int enter_size();

    void display_board();
    void display_board(bool wasIllegal);
    int input_coord();
    void switch_turn();
    bool is_x_turn();
    int get_size();
    bool is_won();

    bool is_legal_move(int const &x, int const &y);
    void make_move(int const &x, int const &y);

    int get_item_at_square(int const &x, int const &y);
    void set_item_at_square(int const &x, int const &y, int const &val);
    
};