#ifndef UNTITLED6_NUMERICAL_TIC_TAC_TOE_H
#define UNTITLED6_NUMERICAL_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <vector>
using namespace std;
class Numerical_Tic_Tac_Toe_Board: public Board<int> {
    vector<int> used_numbers;
public:
    Numerical_Tic_Tac_Toe_Board();
    bool update_board(Move<int>* move);
    bool is_win(Player<int>* player);
    bool is_lose(Player<int>* player);
    bool is_draw(Player<int>* player);
    bool game_is_over(Player<int>* player);
};

class Numerical_Tic_Tac_Toe_UI: public UI<int> {
public:
    Numerical_Tic_Tac_Toe_UI();
    Player<int>* create_player(std::string& name, int symbol, PlayerType type);
    virtual Move<int>* get_move(Player<int>* player);
};

#endif //UNTITLED6_NUMERICAL_TIC_TAC_TOE_H