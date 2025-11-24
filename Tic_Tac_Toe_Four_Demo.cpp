#include<iostream>
using namespace std;
#include<cmath>
#include"Tic_Tac_Toe_Four.h"
void Tic_Tac_Toe_Four() //yarra
{
    srand(static_cast<unsigned int>(time(0)));
    UI<char>* game_ui = new XO4_UI();
    Board<char>* board = new XO4_board();
    Player<char>** players = game_ui->setup_players();
    GameManager<char> game(board , players , game_ui);
    game.run();
    delete board;
    for (int i = 0; i < 2; ++i) delete players[i];
    delete[] players;
    delete game_ui;
}
