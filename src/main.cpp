#include<iostream>
#include"game2048.h"
#include"Right.h"

using namespace std;

int main()
{
    Game2048* game = new Game2048;

    for(int i = 0; i < 3; ++i){
        game->showBoard();
        game->moveLeft();
        cout << endl;
        game->showBoard();
        game->moveRight();
        cout << endl;
    }


    delete game;
    return 0;
}
