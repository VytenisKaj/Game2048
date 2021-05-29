#include "EmptyTile.h"
#include<sstream>
#include<iomanip>

using namespace std;

EmptyTile::EmptyTile(int x, int y) :  Tile(0, x, y)
{

}

string EmptyTile::toString(){
    std::stringstream ss;

    ss << setw(5) << (char)176;
    return ss.str();
}
