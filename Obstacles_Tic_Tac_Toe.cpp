#include"BoardGame_Classes.h"
#include"Obstacles_Tic_Tac_Toe.h"
obstacles_board::obstacles_board():Board(6,6)
{
    for (auto& row: board)
        for (auto& cell: row)
            cell = blank_symbol;
}
bool obstacles_board::update_board(Move<char>* move)
{
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();
    if (board[x][y] == blank_symbol)
    {
        board[x][y] = symbol;
        return true;
    }
    return false;
}

void obstacles_board::add_obstacles(int count )
{
    int added = 0;
    while (added < count)
    {
        int x=rand()%rows;
        int y = rand()%columns;
        if (board[x][y]==blank_symbol)
        {
            board[x][y] = '#';
            added++;
        }
    }
}
obstacles_board::~obstacles_board() {}
bool obstacles_board::is_win(Player<char>* player) {
    char symbol = player->get_symbol();
    return false;
}
bool obstacles_board::is_draw(Player<char>*) { return false; }
bool obstacles_board::game_is_over(Player<char>* player) {
    return is_win(player);
}
obstacles_UI::obstacles_UI() : UI<char>("Welcome to Obstacles Tic Tac Toe Game", 3) {}
obstacles_UI::~obstacles_UI(){}
Player<char>* obstacles_UI::create_player(string& name, char symbol, PlayerType type) {
    return new Player<char>(name, symbol, type);
}
Move<char>* obstacles_UI::get_move(Player<char>* player) {
    int x, y;
    cout << player->get_name() << " (" << player->get_symbol() << ") enter move (row col): ";
    cin >> x >> y;
    return new Move<char>(x, y, player->get_symbol());
}
