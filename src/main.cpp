#include<iostream>
#include"game2048.h"
#include<string>

using namespace std;

int main(){

    Game2048* game = new Game2048;
    game->run();
    delete game;

    return 0;
}
