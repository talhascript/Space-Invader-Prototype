#include <graphics.h>
#include "laser.hpp"
#include "heart.hpp"
#include "space_ship.hpp"

class Alien;
class Heart;

Laser::Laser(int _x, int _y, int _size, int _color, int _speed) : SpaceEntity(_x, _y),
                                                                    size(_size), 
                                                                    speed(_speed),
                                                                    color(_color),
                                                                    spaceShip(NULL),
                                                                    active(false){}

bool Laser::getActive() const { return active; }
void Laser::setSpaceShip(SpaceShip *s) { spaceShip = s; }

void Laser::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    fillellipse(x, y, size, size);
}

void Laser::draw() const { drawHelper(color); }

void Laser::undraw() const { drawHelper(BLACK); }

void Laser::move()
{   

    if (active == 0) return;
    undraw();
    y -= speed; // causes the bullet to move up

    if (y > 0)
        draw();
    else
        active = false;
}


void Laser::startPoint()
{
    x = spaceShip->getX() + spaceShip->getWidth() / 2;
    y = spaceShip->getY() - size;
    active = true;
}

// intersect: general function to test intersection.
//    Key idea: an intersection between  two shapes is detected when the distance
//      between the center of the objects (d) is less than or equal to the sum
//      of the "radius" of both objects. 
bool Laser::intersect(int cx1, int cy1, int rx1, int ry1,
			   int cx2, int cy2, int rx2, int ry2)
{
	int dx = abs(cx2-cx1);
	int dy = abs(cy2-cy1);
	int sum_rx = rx1+rx2;
	int sum_ry = ry1+ry2;

	return ( (dx <=sum_rx) && (dy<=sum_ry) );
}



// collide: function to test intersection between a rectangle and a circle
// Parameters: alien->getX(), alien->getY()  = top left corner of the rectangle
//             alien->getWidth(), alien->getHeight()    = width and height of rectangle
//             x, y, size = center and radius of the circle


bool Laser::collide(Alien *alien){ //overloaded collide method
    bool check =  false;
    check= intersect(alien->getX() + (alien->getWidth()/2.0), alien->getY() + (alien->getHeight()/2.0), (alien->getWidth()/2.0), (alien->getHeight()/2.0), x,y,size,size);
    return check;
}


// collide: function to test intersection between a rectangle and a circle
// Parameters: heart->getX(), heart->getY()  = top left corner of the rectangle
//             heart->getWidth(), heart->getHeight()    = width and height of rectangle
//             x, y, size = center and radius of the circle

bool Laser::collide(Heart *heart){ //overloaded collide method
    bool check =  false;
    check= intersect(heart->getX() + (heart->getWidth()/2.0), heart->getY() + (heart->getHeight()/2.0), (heart->getWidth()/2.0), (heart->getHeight()/2.0), x,y,size,size);
    return check;
}



