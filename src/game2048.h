#ifndef GAME2048_H
#define GAME2048_H

#define BOARD_SIZE 4
#define ACTION_AMOUNT 4

#include"Tile.h"

class Action;

class Game2048
{

    friend class Left;
    friend class Right;
    friend class Up;
    friend class Down;


    private:
        // Holds the board of the game
        Tile* board[BOARD_SIZE][BOARD_SIZE];
        // Holds locations of non-empty tiles
        int used[BOARD_SIZE][BOARD_SIZE];
        // Counts score
        int score;
        // Defines, if game is ongoing
        bool isActive;
        // Left = 0, Right = 1, Up = 2, Down = 3
        Action* actions[ACTION_AMOUNT];

    public:
        Game2048();
        ~Game2048();
        // Creates gameloop
        void run();

    private:

        // Fills board[][] with EmptyTile(s)
        void initBoard();
        // Randomly places 2 ValueTile(s) on board[][]
        void initGame();
        // Adds ValueTile to the board in random location
        void addValueTile();
        // Merges two ValueTile(s) with the same value together and creates new one, which value = 2*prev_value
        void mergeTiles(Tile** first, Tile** second, Action* action);
        // Shows board on the screen
        void showBoard();
        // Makes all tiles go right
        void moveRight();
        // Makes all tiles go left
        void moveLeft();
        // Makes all tiles go up
        void moveUp();
        // Makes all tiles go sown
        void moveDown();
        // Checks, if there is free space for new ValueTile
        bool freeSpaceExist();


};

#endif // GAME2048_H
