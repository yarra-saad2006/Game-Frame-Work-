//
// Created by i7 on 11/25/2025.
//

#ifndef UNTITLED8_OBSTACLES_TIC_TAC_TOE_H
#define UNTITLED8_OBSTACLES_TIC_TAC_TOE_H
#include "BoardGame_Classes.h"

#endif //UNTITLED8_OBSTACLES_TIC_TAC_TOE_H
#include"BoardGame_Classes.h"
class obstacles_board:public Board<char>
{
    char blank_symbol='.';
    public:
    obstacles_board();
    ~obstacles_board() override ;
    bool update_board(Move<char>* move);
    bool is_win(Player<char>* player);
    bool is_lose(Player<char>*) { return false; };
    bool is_draw(Player<char>* player);
    bool game_is_over(Player<char>* player);
    void add_obstacles(int count=2) ;
};
class obstacles_UI:public UI<char>
{
    public:
    obstacles_UI();
    ~obstacles_UI() override ;
    Player<char>* create_player(string& name, char symbol, PlayerType type);
    virtual Move<char>* get_move(Player<char>* player);
};
