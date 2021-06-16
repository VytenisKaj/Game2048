#include "game2048.h"

#include"EmptyTile.h"
#include<iostream>
#include<ctime>
#include"ValueTile.h"
#include"Right.h"
#include"Left.h"
#include"Up.h"
#include"Down.h"

#include<iomanip>

#define FOUR_PROB 4 // Probobility of '4' appearing as anew tile instead of '2'. Calculated 1/FOUR_PROB

using namespace std;

Game2048::Game2048()
{
    initBoard();
    initGame();
    actions[0] = new Left;
    actions[1] = new Right;
    actions[2] = new Up;
    actions[3] = new Down;
    score = 0;
    isActive = true;
    highestTileValue = 2;
}

Game2048::~Game2048(){

    for(int i = 0; i < ACTION_AMOUNT; ++i){
        delete actions[i];
    }
    deleteBoard();
}

void Game2048::initBoard(){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
                used[i][j] = 0;
                board[i][j] = new EmptyTile(i,j);
        }
    }
}


// Not used with GUI, console application method
void Game2048::showBoard(){
    string temp = "Score: " + to_string(score);
    cout << setw(20) << temp << "\n" << endl;
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
            cout << board[i][j]->toString();
            if(j == BOARD_SIZE - 1){
                cout << endl;
            }
        }
    }
   /* cout << endl;
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
            cout << setw(5) << used[i][j];
            if(j == BOARD_SIZE - 1){
                cout << endl;
            }
        }
    }*/
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
    board[x1][y1] = new ValueTile(2, x1, y1);
    used[x1][y1] = 1;
}

void Game2048::addValueTile(){
    if(!freeSpaceExist()){
        isActive = false;
        return;
    }
    int x = rand() % BOARD_SIZE;
    int y = rand() % BOARD_SIZE;
    while( used[x][y] == 1 || dynamic_cast<ValueTile*>(board[x][y])){ // due to used[][] bugs, this had a possibility to delete existing ValueTiles. Once bugs are fixed, dynamic_cast can be removed
        x = rand() % BOARD_SIZE;
        y = rand() % BOARD_SIZE;
    }
    delete board[x][y];

    int temp = rand() % FOUR_PROB == 0? 4 : 2;
    board[x][y] = new ValueTile(temp, x, y);
    used[x][y] = 1;

}

void Game2048::mergeTiles(Tile** first, Tile** second, Action* action){
    if((*first)->getValue() != (*second)->getValue()){
        return;
    }
    int newVal = (*first)->getValue() * 2;
    score += newVal;
    highestTileValue = newVal > highestTileValue ? newVal : highestTileValue;
    int fX = (*first)->getX();
    int fY = (*first)->getY();
    int sX = (*second)->getX();
    int sY = (*second)->getY();

    if(dynamic_cast<Left*>(action) || dynamic_cast<Up*>(action)){
        delete *first;
        delete *second;
        *first = new EmptyTile(sX, sY); 
        used[fX][fY] = 0; // Possible location of bugs related to used[][] containing wrong information
        *second = new ValueTile(newVal, fX, fY);
    }

    if(dynamic_cast<Right*>(action) || dynamic_cast<Down*>(action)){
        delete *first;
        delete *second;
        *first = new EmptyTile(fX, fY);
        used[fX][fY] = 0;
        *second = new ValueTile(newVal, sX, sY);

    }

}

void Game2048::moveRight(){
    actions[1]->run(this);
}

void Game2048::moveLeft(){
    actions[0]->run(this);
}

void Game2048::moveUp(){
    actions[2]->run(this);
}

void Game2048::moveDown(){
    actions[3]->run(this);
}

void Game2048::run(){
    while(isActive){
       
    }
}

bool Game2048::freeSpaceExist(){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE; ++j){
            if(used[i][j] == 0){
                if (dynamic_cast<EmptyTile*>(board[i][j])) { // Because of used[][] bugs, game freezed. 'if' can be removed once bugs are fixed.
                    return true;
                }
            }
        }
    }
    return false;
}

bool Game2048::getIsActive() {
    return isActive;
}

int Game2048::getScore() {
    return score;
}

void Game2048::resetGame() {
    deleteBoard();
    initBoard();
    initGame();
    isActive = true;
}

void Game2048::deleteBoard() {

    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            delete board[i][j];
        }
    }
}

int Game2048::getHighestTileValue() {
    return highestTileValue;
}

void Game2048::resetScore() {
    score = 0;
}

void Game2048::resetHighestTileValue()
{
    this->highestTileValue = 2;
}
