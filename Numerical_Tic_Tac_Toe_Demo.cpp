#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "BoardGame_Classes.h"
#include "Numerical_Tic_Tac_Toe.h"
using namespace std;
int Numerical_Tic_Tac_Toe() {
    srand(static_cast<unsigned int>(time(0)));

    UI<int>* game_ui = new Numerical_Tic_Tac_Toe_UI();
    Board<int>* num_board = new Numerical_Tic_Tac_Toe_Board();
    Player<int>** players = game_ui->setup_players();

    GameManager<int> num_game(num_board, players, game_ui);
    num_game.run();

    delete num_board;
    for (int i = 0; i < 2; ++i)
        delete players[i];
    delete[] players;
    return 0;
}