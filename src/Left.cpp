#include "Left.h"
#include"game2048.h"
#include"ValueTile.h"

Left::Left()
{
    //ctor
}

void Left::run(Game2048* game){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE ; ++j){
            if(dynamic_cast<ValueTile*>(game->board[i][j])){
                int x = j;
                while(x - 1 != -1){
                    if(dynamic_cast<ValueTile*>(game->board[i][x-1])){
                        game->mergeTiles(&(game->board[i][x]), &(game->board[i][x-1]),this);
                        ++x; 
                        break;
                    }
                    std::swap(game->board[i][x],game->board[i][x-1]);
                    game->board[i][x]->setX(i);
                    game->board[i][x]->setY(x);
                    game->board[i][x-1]->setX(i);
                    game->board[i][x-1]->setY(x-1);
                    game->used[i][x] = 0;
                    game->used[i][x-1] = 1;
                    --x;
                }
            }
        }
    }
    game->addValueTile();

}
