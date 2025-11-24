#include"Board_Game_Classes.h"
class XO4_board : public Board<char>
{
    char blank_symbol = '.';
    public:
    XO4_board() ;
    ~XO4_board() override;
    bool update_board(Move<char>* move);
    bool is_win(Player<char>* player);
    bool is_lose(Player<char>*) { return false; };
    bool is_draw(Player<char>* player);
    bool game_is_over(Player<char>* player);
};
class XO4_UI : public UI<char>
{
    public:
    XO4_UI();
    ~XO4_UI() {};
    Player<char>* create_player(string& name, char symbol, PlayerType type);
    virtual Move<char>* get_move(Player<char>* player);
};
