#include<iostream>
using namespace std;
#include"Obstacles_Tic_Tac_Toe.h"
void Obstacles_Tic_Tac_Toe()//Group
{
    srand(static_cast<unsigned int>(time(0)));
    UI<char>* game_ui = new obstacles_UI();
    obstacles_board* xo6 = new obstacles_board();
    Board<char>* board = xo6;
    Player<char>** players = game_ui->setup_players();
    GameManager<char> game(board , players , game_ui);
    int turn = 0;
    while (!board->game_is_over(players[turn % 2])) {
        game_ui->display_board_matrix(board->get_board_matrix());
        Move<char>* move = game_ui->get_move(players[turn % 2]);
        if (board->update_board(move)) {
            turn++;
            if (turn % 2 == 0) {
                xo6->add_obstacles(2);
                cout << "[Obstacles] Added 2 obstacles.\n";
            }
        }
        delete move;
    }
    delete board;
    for (int i = 0; i < 2; ++i) delete players[i];
    delete[] players;
    delete game_ui;
}
