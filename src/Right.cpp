#include "Right.h"
#include"game2048.h"
#include"ValueTile.h"

Right::Right()
{
    //ctor
}

void Right::run(Game2048* game){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = BOARD_SIZE - 1; j >= 0 ; --j){
            if(dynamic_cast<ValueTile*>(game->board[i][j])){
                int x = j;
                while(x + 1 != BOARD_SIZE){
                    if(dynamic_cast<ValueTile*>(game->board[i][x+1])){
                        game->mergeTiles(&(game->board[i][x]), &(game->board[i][x+1]), this);
                        --x; 
                        break;
                    }
                    std::swap(game->board[i][x],game->board[i][x+1]);
                    game->board[i][x]->setX(i);
                    game->board[i][x]->setY(x);
                    game->board[i][x+1]->setX(i);
                    game->board[i][x+1]->setY(x+1);
                    game->used[i][x] = 0;
                    game->used[i][x+1] = 1;
                    ++x;
                }
            }
        }
    }
    game->addValueTile();
}
