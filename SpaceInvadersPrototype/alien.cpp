include <graphics.h>
#include "alien.hpp"
#include <iostream>
#include "space_ship.hpp"
using namespace std;


Alien ::Alien(int _x, int _y, int _width, int _height, int _color, int _dy) : SpaceEntity(_x, _y, _width, _height, _color),
                                                                              dy(_dy), isAlive(true) {

                                                                                    spaceShip = NULL;
                                                                                }


void Alien ::move()
{
    if(isAlive ==  false) return;
    undraw();
    y += dy;
    draw();
}

void Alien ::draw() const
{   
    setcolor(color);
    setfillstyle(SOLID_FILL, color);
    bar(x, y, x + width, y + height);
}


void Alien ::undraw() const { 
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);

    }

bool  Alien ::getAliveStatus() const{
    return isAlive;
}

void Alien :: die(){
    isAlive =false;
    this->undraw();
}
bool Alien ::CrossesLine(int yLength) // this method takes the length of the line as a parameter
{

    if (!start || oneHit == 1) // !start=true, so we can enter in the next if statement
    { 
        if ((y > yLength) && (oneHit == 0))
        {
            start = true; //* start will become true if the alien collides with the line
            oneHit = 1;   //* also oneHit will become 1
        }
        else if (oneHit == 1)
        {   
           
            start = false;
           
        }
    }

    return start; //* start containing the true value will return when the collision happens for the first time
}


void  Alien ::decreaseShipLife(SpaceShip *spaceShip){
    spaceShip->SubtractShipLife();
}

