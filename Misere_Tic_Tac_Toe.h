#ifndef MISERE_TIC_TAC_TOE_H
#define MISERE_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <vector>

using namespace std;
class Misere_Tic_Tac_Toe_Board : public Board<char> {
private:
    char blank_symbol = '.';
public:
    Misere_Tic_Tac_Toe_Board();
    bool update_board(Move<char>* move);
    bool is_win(Player<char>* player) { return false; };
    bool is_lose(Player<char>* player);
    bool is_draw(Player<char>* player);
    bool game_is_over(Player<char>* player);
};

class Misere_Tic_Tac_Toe_UI : public UI<char> {
public:
    Misere_Tic_Tac_Toe_UI();
    Player<char>* create_player(std::string& name, char symbol, PlayerType type);
    virtual Move<char>* get_move(Player<char>* player);
};

#endif //UNTITLED6_MISERE_TIC_TAC_TOE_H