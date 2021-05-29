#ifndef VALUETILE_H
#define VALUETILE_H

#include "Tile.h"
#include<string>

class ValueTile : public Tile
{
    public:
        ValueTile(int value, int x, int y);
        std::string toString();

};

#endif // VALUETILE_H
