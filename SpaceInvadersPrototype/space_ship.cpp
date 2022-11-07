#include <graphics.h>
#include "space_ship.hpp"
#include "laser.hpp"

#include <iostream>
using namespace std;

SpaceShip::SpaceShip(int _x, int _y, int _width, int _height, int _color) :SpaceEntity(_x, _y, _width, _height, _color)
{   
    for (int i = 0; i < MAXBULLET; i++){
        bullets[i].setSpaceShip(this);
    }

    shipLife = 3;
}


void SpaceShip::shoot()
{
    int foundAt = -1;
    for (int i = 0; i < MAXBULLET; i++)
    {
        if (!(bullets[i].getActive())) // no bullets are shot
        {
            foundAt = i; //foundAt takes value from 0 to 10
            break;
        }
    }

    if (foundAt != -1){ // if foundAt is not -1
        bullets[foundAt].startPoint(); 
        bullets[foundAt].draw();
    }
}

void SpaceShip::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    bar(x, y, x + width, y + height);
}

void SpaceShip::draw() const { drawHelper(color); }
void SpaceShip::undraw() const { drawHelper(BLACK); }
void SpaceShip::move(int dx)
{
    undraw();
    x += dx;
    draw();
}

void SpaceShip::doAction()
{
    for (int i = 0; i < MAXBULLET; i++)
        bullets[i].move();
}

int SpaceShip::getShipLife() const{
    return shipLife;

}


Laser SpaceShip::getBullet(){
        bullets[0].setSpaceShip(this);
        return bullets[0];
}  


void SpaceShip::SubtractShipLife(){
    shipLife=shipLife-1;
}

void SpaceShip::AddShipLife(){
    shipLife=shipLife+1;
}





/* 

Example:
* first case
! if  the shiplife is  3, x=+1
    ? the shiplife value  will not increase, it will remain 3 
! else if the shiplife is 2, x=+1
    ? the shiplife value will increase by one
* second case
! if the shiplife is 3, x=-1
    ? the shiplife value will derease by 1
! else if the shiplife is 0, x=-1
    ? the shiplife value will not decerase, and it will remain 0
*/ 