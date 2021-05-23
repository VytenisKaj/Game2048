#include "Left.h"
#include"game2048.h"
#include"ValueTile.h"

Game2048::Left::Left()
{
    //ctor
}

void Game2048::Left::run(Game2048* game){
    for(int i = 0; i < BOARD_SIZE; ++i){
        for(int j = 0; j < BOARD_SIZE ; ++j){
            if(dynamic_cast<ValueTile*>(game->board[i][j])){
                int x = j;
                while(x - 1 != -1){
                    if(dynamic_cast<ValueTile*>(game->board[i][x-1])){
                        break;
                    }
                    std::swap(game->board[i][x],game->board[i][x-1]);
                    game->used[i][x] = 0;
                    game->used[i][x-1] = 1;
                    --x;
                }
            }
        }
    }
    game->addValueTile();

}
