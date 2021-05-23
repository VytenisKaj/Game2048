#ifndef TILE_H
#define TILE_H

#include<string>

class Tile
{
    protected:
        int value;
        int posX;
        int posY;
    public:
        Tile();
        Tile(int value, int posX, int posY);
        virtual ~Tile();
        virtual std::string toString() = 0;
};

#endif // TILE_H
