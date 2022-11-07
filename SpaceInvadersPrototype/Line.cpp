#include <graphics.h>
#include "space_ship.hpp"
#include "laser.hpp"
#include "Line.hpp"

Line::Line(int _x, int _y, int _width, int _height, int _color) : SpaceEntity(_x, _y, _width, _height, _color)
{

}


void Line::drawHelper(int c) const
{
    setcolor(c);
    setfillstyle(SOLID_FILL, c);
    bar(x, y, x + width, y + height);

    if(getColor()==0) setcolor(YELLOW); //if some shape moves over the line, line becomes black. 
                                         // but using this if statement, line becomes yellow again.
}

void Line::draw() const { drawHelper(color); }
int Line:: getColor() const{ return color;}


