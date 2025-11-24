#include<iostream>
#include "Board_Game_Classes.h"
using namespace std;
void Sus_Game(); //Tasneem
void Four_In_a_Row(); //Tasneem
void Tic_Tac_Toe(); //Reem
void Word_Tic_Tac_Toe(); //Reem
int Misere_Tic_Tac_Toe(); //Nada
void Diamond_Tic_Tac_Toe(); //Nada
void Tic_Tac_Toe_Four(); //yarra
void Pyramid_Tic_Tac_Toe(); //Yarra
int Numerical_Tic_Tac_Toe(); //Group
void Obstacles_Tic_Tac_Toe(); //Group
void Infinty_Tic_Tac_Toe(); //Group
void Ultimate_Tic_Tac_Toe(); //Group + Bouns
void Memory_Tic_Tac_Toe(); //Group + Bouns
int XO(); //DR.EL_Ramly
int main()
{
    int choice;
    do
    {
        cout<<"========================================="<<endl;
        cout<<"Welcome!"<<endl;
        cout<<"GAME FRAMEWORK MENUE"<<endl;
        cout<<"========================================="<<endl;
        cout<<"1. Sus Game\n";
        cout<<"2. Four In A Row Game\n";
        cout<<"3. 5x5 Tic Tac Toe\n";
        cout<<"4. Word Tic Tac Toe\n";
        cout<<"5. Misère Tic Tac Toe\n";
        cout<<"6. Diamond Tic Tac Toe\n";
        cout<<"7. 4x4 Tic Tac Toe\n";
        cout<<"8. Pyramid Tic Tac Toe\n";
        cout<<"9. Numerical Tic Tac Toe\n";
        cout<<"10. Obstacles Tic Tac Toe\n";
        cout<<"11. Infinty Tic Tac Toe\n";
        cout<<"12. Ultimate Tic Tac Toe\n";
        cout<<"13. Memory Tic Tac Toe\n";
        cout<<"14. XO Board\n";
        cout<<"0 Exit\n";
        cout<<"========================================="<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            // case 1: Sus_Game(); break;
            // case 2 :Four_In_a_Row(); break;
            // case 3 : Tic_Tac_Toe(); break;
            // case 4 : Word_Tic_Tac_Toe(); break;
            case 5 : Misere_Tic_Tac_Toe(); break;
            // case 6 : Diamond_Tic_Tac_Toe(); break;
            case 7 : Tic_Tac_Toe_Four(); break;
            // case 8 : Pyramid_Tic_Tac_Toe(); break;
            case 9 : Numerical_Tic_Tac_Toe(); break;
            // case 10 : Obstacles_Tic_Tac_Toe(); break;
            // case 11 : Infinty_Tic_Tac_Toe(); break;
            // case 12 : Ultimate_Tic_Tac_Toe(); break;
            // case 13 : Memory_Tic_Tac_Toe(); break;
            case 14: XO(); break;
            case 0 : cout<<"Goodbye!"<<endl; break;
        default: cout << "Invalid choice, try again.\n";
        }
    }
    while (choice !=0);
    return 0;
}
