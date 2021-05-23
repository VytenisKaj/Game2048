#ifndef GAME2048_H
#define GAME2048_H

#define BOARD_SIZE 4

#include"Tile.h"


class Game2048
{
    class Right;
    class Left;
    private:
        Tile* board[BOARD_SIZE][BOARD_SIZE];
        int used[BOARD_SIZE][BOARD_SIZE];
        Right* right;
        Left* left;


    public:
        Game2048();
        ~Game2048();
        void showBoard();
        void moveRight();
        void moveLeft();

    private:
        void initBoard();
        void initGame();
        void addValueTile();

};

#endif // GAME2048_H
