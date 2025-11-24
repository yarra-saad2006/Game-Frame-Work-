#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "BoardGame_Classes.h"
#include "Misere_Tic_Tac_Toe.h"
using namespace std;

int Misere_Tic_Tac_Toe() {

    srand(static_cast<unsigned int>(time(0)));
    UI<char>* game_ui = new Misere_Tic_Tac_Toe_UI();
    Board<char>* xo_board = new Misere_Tic_Tac_Toe_Board();
    Player<char>** players = game_ui->setup_players();
    GameManager<char> x_o_game(xo_board, players, game_ui);
    x_o_game.run();
    delete xo_board;
    for (int i = 0; i < 2; ++i) {
        delete players[i];
    }
    delete[] players;

    return 0; 
}
