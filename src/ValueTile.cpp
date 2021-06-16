#include "ValueTile.h"
#include<sstream>

using namespace std;

ValueTile::ValueTile(int value, int x, int y) : Tile(value, x, y)
{
    //ctor
}

string ValueTile::toString(){
    std::stringstream ss;
    ss << value;
    return ss.str();
}


