// Created by Vytenis Kajackas 2021-06-09
// header of main game class


#ifndef GAME2048_H
#define GAME2048_H

// Defines size of a board
#define BOARD_SIZE 4
// Defines amount of action, that user can make
#define ACTION_AMOUNT 4

#include"Tile.h"

class Action;

class Game2048
{

    friend class Left;
    friend class Right;
    friend class Up;
    friend class Down;
    friend class cMain;


    private:

        // Holds the board of the game
        Tile* board[BOARD_SIZE][BOARD_SIZE];

        // Holds locations of non-empty tiles 
        // NOTE created to improve performance, but due to infrequent, but game breaking bugs, 
        // temporary not used or combined with less efficient methods (look mergeTiles, addValueTile, freeSpaceExists)
        int used[BOARD_SIZE][BOARD_SIZE];

        // Counts score
        int score;
        // Saves current highest value of a tile
        int highestTileValue;
        // Defines, if game is ongoing
        bool isActive;
        // Left = 0, Right = 1, Up = 2, Down = 3
        Action* actions[ACTION_AMOUNT];

    public:
        Game2048();
        ~Game2048();
        // Creates gameloop
        void run();

        // Returns if game is active
        bool getIsActive();
        // Returns current score
        int getScore();
        // Returns current highest value of a tile 
        int getHighestTileValue();
        // Resets game 
        void resetGame();
        void resetScore();
        void resetHighestTileValue();

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
        // Deletes board
        void deleteBoard();
        


};

#endif // GAME2048_H
