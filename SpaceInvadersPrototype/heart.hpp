#ifndef HEART_H
#define HEART_H

#include <graphics.h>
#include "SpaceEntity.hpp"

class SpaceShip;
class Heart: public SpaceEntity
{
    private:
    int dy;       

    bool start=false; //These attributes are here to check if heart passes the line
    int  oneHit=0;    //These attributes are here to check if heart passes the line

    bool isAlive;     //checks if the heart is alive or not
    SpaceShip *spaceShip;
    void drawHelper(int c) const; //helper method

    public:
	Heart(int _x = 0, int _y = 0, int _width = 0, int _height = 0, int _color = BLUE, int _dy=1);


    bool getAliveStatus() const;
    void setAliveStatus(bool status);
    void  die();

    
	void draw() const;
	void undraw() const;

    void move();
    bool CrossesLine(int yLength);

    void increaseShipLife(SpaceShip *spaceShip);

};




#endif
