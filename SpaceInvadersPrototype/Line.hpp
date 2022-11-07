#ifndef LINE_H
#define LINE_H
#include "SpaceEntity.hpp"
#include <graphics.h>

class Line: public SpaceEntity
{

    public:
    Line(int _x, int _y, int _width , int _height = 1, int _color = YELLOW);
    void drawHelper(int ) const;
    void draw() const;
    int getColor() const;

};

#endif