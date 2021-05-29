#include"Tile.h"

Tile::Tile(){


}

Tile::Tile(int value, int posX, int posY){
    this->value = value;
    this->posX = posX;
    this->posY = posY;
}

Tile::~Tile(){

}

Tile::Tile(const Tile& other){
    this->setValue(other.getValue());
    this->setX(other.getX());
    this->setY(other.getY());

}

int Tile::getValue() const{
    return value;
}

void Tile::setValue(int val){
    value = val;
}

int Tile::getX() const{
    return posX;
}

void Tile::setX(int val){
    posX = val;
}

int Tile::getY() const{
    return posY;
}

void Tile::setY(int val){
    posY = val;
}
