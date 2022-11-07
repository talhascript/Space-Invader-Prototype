#include <graphics.h>
#include "SpaceEntity.hpp"

SpaceEntity::SpaceEntity(int _x, int _y, int _width, int _height, int _color) 

                            : x(_x), y(_y), width(_width), height(_height) , color(_color) {}


int SpaceEntity ::getX() const
{
    return x;
}
int SpaceEntity ::getY() const
{
    return y;
}
int SpaceEntity ::getWidth() const
{
    return width;
}
int SpaceEntity ::getHeight() const
{
    return height;
}
