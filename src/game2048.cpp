#include "game2048.h"

#include"EmptyTile.h"
#include<iostream>
#include<ctime>
#include"ValueTile.h"
#include"Right.h"
#include"Left.h"

using namespace std;

Game2048::Game2048()
{
    initBoard();
    initGame();
    right = new Right;
    left = new Left;
}

Game2048::~Game2048(){
    delete right;
    delete left;
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
                delete board[i][j];
        }
    }
}

void Game2048::initBoard(){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
                used[i][j] = 0;
                board[i][j] = new EmptyTile(i,j);
        }
    }
}

void Game2048::showBoard(){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
            cout << board[i][j]->toString();
            if(j == 3){
                cout << endl;
            }
        }
    }
}

void Game2048::initGame(){
    srand(time(NULL));
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    int x1 = rand() % BOARD_SIZE;
    int y1 = rand() % BOARD_SIZE;
    while(x == x1 && y == y1){
        x1 = rand() % BOARD_SIZE;
    }

    delete board[x][y];
    delete board[x1][y1];

    board[x][y] = new ValueTile(2, x, y);
    used[x][y] = 1;
    board[x1][y1] = new ValueTile(3, x1, y1);
    used[x1][y1] = 1;
}

void Game2048::addValueTile(){
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    while( used[x][y] == 1){
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
    }
    delete board[x][y];
    board[x][y] = new ValueTile(4, x, y);

}

void Game2048::moveRight(){
    right->run(this);
}

void Game2048::moveLeft(){
    left->run(this);
}
