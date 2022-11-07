#ifndef SPACEENTITY_H
#define SPACEENTITY_H

class SpaceEntity
{
protected:
int x, y, width, height, color; //* these attributes are used by spaceship, line, alien and heart;

public:
SpaceEntity(int _x = 0, int _y = 0, int _width =0,  int _height=0, int _color=0);

virtual void draw() const {};
virtual void undraw() const {};
virtual void move()  {};


int getX() const;
int getY() const;
int getWidth() const;
int getHeight() const;

};

#endif