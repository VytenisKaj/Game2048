#include "ValueTile.h"
#include<sstream>
#include<iomanip>

using namespace std;

ValueTile::ValueTile(int value, int x, int y) : Tile(value, x, y)
{
    //ctor
}

string ValueTile::toString(){
    std::stringstream ss;
    ss << setw(5) << value;
    return ss.str();
}


