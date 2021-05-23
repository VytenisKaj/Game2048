#ifndef EMPTYTILE_H
#define EMPTYTILE_H

#include "Tile.h"
#include<string>

using std::string;

class EmptyTile : public Tile
{

    public:
        EmptyTile(int x, int y);
        string toString();

};

#endif // EMPTYTILE_H
