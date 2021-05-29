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
        Tile(const Tile& other);
        virtual ~Tile();
        virtual std::string toString() = 0;
        int getValue() const;
        void setValue(int val);
        int getX() const;
        void setX(int val);
        int getY() const;
        void setY(int val);

};

#endif // TILE_H
