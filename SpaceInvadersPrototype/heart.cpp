#include <graphics.h>
#include "heart.hpp"
#include "space_ship.hpp"

Heart :: Heart(int _x, int _y, int _width, int _height, int _color, int _dy) :  SpaceEntity(_x, _y, _width, _height, _color),
                                                                                dy(_dy), isAlive(true) {

                                                                                    spaceShip = NULL;
                                                                                }


void Heart :: move(){
        if(isAlive  ==  false) return;
        undraw();
        y += dy;
        draw();
}

void Heart::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    bar(x, y, x + width, y + height);
}

void Heart::draw() const { drawHelper(color); }


void Heart ::undraw() const { 
    setcolor(BLACK);
    setfillstyle(SOLID_FILL, BLACK);
    bar(x, y, x + width, y + height);
    }


bool  Heart ::getAliveStatus() const{
    return isAlive;
}

void Heart :: die(){
    isAlive =false;
    this->undraw();
}




bool Heart ::CrossesLine(int yLength)// this function takes the length of the line as a parameter // change
{

    if (!start || oneHit == 1) // !start=true, so we can enter in the next if statement
    {
        if (y > yLength && oneHit == 0)
        {
            start = true; //* start will become true if the heart collides with the line
            oneHit = 1;   //* also oneHit will become 1
        }
        else if (oneHit == 1)
        {   
           
            start = false;
            
        }
    }

    return start; //* start with the true value will return when the collision happens for the first time
}




void  Heart ::increaseShipLife(SpaceShip *spaceShip){
    spaceShip->AddShipLife();
}
