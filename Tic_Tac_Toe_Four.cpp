#include "BoardGame_Classes.h"
#include "Tic_Tac_Toe_Four.h"

XO4_board::XO4_board() : Board<char>(4,4) {
    for (auto& row: board)
        for (auto& cell: row)
            cell = blank_symbol;

    board[0][0] = 'O';
    board[0][1] = 'X';
    board[0][2] = 'O';
    board[0][3] = 'X';

    board[3][0] = 'X';
    board[3][1] = 'O';
    board[3][2] = 'X';
    board[3][3] = 'O';
}

XO4_board::~XO4_board() {}

bool XO4_board::update_board(Move<char>* move) {
    int x = move->get_x();
    int y = move->get_y();
    char symbol = move->get_symbol();

    for (int i=0; i<rows; i++) {
        for (int j=0; j<columns; j++) {
            if (board[i][j] == symbol) {
                if (board[x][y] == blank_symbol &&
                    ((abs(x - i) == 1 && y == j) || (abs(y - j) == 1 && x == i))) {
                    board[i][j] = blank_symbol;
                    board[x][y] = symbol;
                    return true;
                    }
            }
        }
    }
    return false;
}

bool XO4_board::is_win(Player<char>* player) {
    char symbol = player->get_symbol();
    return false;
}

bool XO4_board::is_draw(Player<char>*) { return false; }

bool XO4_board::game_is_over(Player<char>* player) {
    return is_win(player);
}

// ================= UI =================
XO4_UI::XO4_UI() : UI<char>("Welcome to 4x4 Moving XO Game", 3) {}

Player<char>* XO4_UI::create_player(string& name, char symbol, PlayerType type) {
    return new Player<char>(name, symbol, type);
}

Move<char>* XO4_UI::get_move(Player<char>* player) {
    int x, y;
    cout << player->get_name() << " (" << player->get_symbol() << ") enter move (row col): ";
    cin >> x >> y;
    return new Move<char>(x, y, player->get_symbol());
}
