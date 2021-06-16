#include "EmptyTile.h"
#include<sstream>

using namespace std;

EmptyTile::EmptyTile(int x, int y) :  Tile(0, x, y)
{

}

string EmptyTile::toString(){
    std::stringstream ss;

    ss << " ";
    return ss.str();
}
