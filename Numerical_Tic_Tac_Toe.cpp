#include <iostream>
#include "Numerical_Tic_Tac_Toe.h"
using namespace std;
Numerical_Tic_Tac_Toe_Board::Numerical_Tic_Tac_Toe_Board() : Board(3, 3) {
    for (auto& row : board)
        for (auto& cell : row)
            cell = 0;
}
bool Numerical_Tic_Tac_Toe_Board::update_board(Move<int>* move) {
    int x = move->get_x();
    int y = move->get_y();
    int num = move->get_symbol();

    if (x < 0 || x >= 3 || y < 0 || y >= 3) return false;
    if (board[x][y] != 0) return false;
    if (find(used_numbers.begin(), used_numbers.end(), num) != used_numbers.end()) return false;
    board[x][y] = num;
    used_numbers.push_back(num);
    n_moves++;
    return true;
}
bool Numerical_Tic_Tac_Toe_Board::is_win(Player<int>* player) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] + board[i][1] + board[i][2] == 15 &&
            board[i][0] && board[i][1] && board[i][2])
            return true;
        if (board[0][i] + board[1][i] + board[2][i] == 15 &&
            board[0][i] && board[1][i] && board[2][i])
            return true;
    }
    if (board[0][0] + board[1][1] + board[2][2] == 15 &&
        board[0][0] && board[1][1] && board[2][2])
        return true;
    if (board[0][2] + board[1][1] + board[2][0] == 15 &&
        board[0][2] && board[1][1] && board[2][0])
        return true;

    return false;
}
bool Numerical_Tic_Tac_Toe_Board::is_lose(Player<int>* player) {
    return false; 
};
bool Numerical_Tic_Tac_Toe_Board::is_draw(Player<int>* player) {
    return n_moves == 9 && !is_win(player);
};
bool Numerical_Tic_Tac_Toe_Board::game_is_over(Player<int>* player) {
    return is_win(player) || is_draw(player); 
};

Numerical_Tic_Tac_Toe_UI::Numerical_Tic_Tac_Toe_UI() : UI<int>("Welcome to FCAI Numerical Tic-Tac-Toe!", 3) {}

Player<int>* Numerical_Tic_Tac_Toe_UI::create_player(string& name, int symbol, PlayerType type) {
    static int player_count = 0;
    player_count++;
    if (player_count == 1)
        symbol = 1;
    else {
        symbol = 2;
        player_count = 0;
    }
    cout << "Creating " << (type == PlayerType::HUMAN ? "human" : "computer")
        << " player: " << name << " (" << (symbol == 1 ? "ODD numbers" : "EVEN numbers") << ")\n";
    return new Player<int>(name, symbol, type);
}

Move<int>* Numerical_Tic_Tac_Toe_UI::get_move(Player<int>* player) {
    int x, y, num;
    if (player->get_type() == PlayerType::COMPUTER) {
        x = rand() % player->get_board_ptr()->get_rows();
        y = rand() % player->get_board_ptr()->get_columns();
        if (player->get_symbol() == 1) {
            int odds[] = { 1, 3, 5, 7, 9 };
            num = odds[rand() % 5];
        }
        else {
            int evens[] = { 2, 4, 6, 8 };
            num = evens[rand() % 4];
        }
        return new Move<int>(x, y, num);
    }
    if (player->get_type() == PlayerType::HUMAN){
        cout << "\nNow it's " << player->get_name() << "'s turn!\n";
        if (player->get_symbol() == 1)
            cout << "You must enter an ODD number (1, 3, 5, 7, 9).\n";
        else
            cout << "You must enter an EVEN number (2, 4, 6, 8).\n";
        cout << "Enter row, column, and number: ";
        cin >> x >> y >> num;
        if ((player->get_symbol() == 1 && num % 2 == 0) ||
            (player->get_symbol() == 2 && num % 2 != 0)) {
            cout << "Wrong number! Player 1 uses odd, Player 2 uses even.\n";
            return get_move(player);
        }
        return new Move<int>(x, y, num);
    }

}