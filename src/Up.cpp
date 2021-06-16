#include "Up.h"
#include"game2048.h"
#include"ValueTile.h"

Up::Up()
{
    //ctor
}

void Up::run(Game2048* game){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE ; ++j){
            if(dynamic_cast<ValueTile*>(game->board[i][j])){
                int x = i;
                while(x - 1 != -1){
                    if(dynamic_cast<ValueTile*>(game->board[x-1][j])){
                        game->mergeTiles(&(game->board[x][j]),&(game->board[x-1][j]),this);
                        ++x; 
                        break;
                    }
                    std::swap(game->board[x][j],game->board[x-1][j]);
                    game->board[x][j]->setX(x);
                    game->board[x][j]->setY(j);
                    game->board[x-1][j]->setX(x-1);
                    game->board[x-1][j]->setY(j);
                    game->used[x][j] = 0;
                    game->used[x-1][j] = 1;
                    --x;
                }
            }
        }
    }
    game->addValueTile();


}
