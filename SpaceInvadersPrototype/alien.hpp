ifndef ALIEN_H
#define ALIEN_H
#include "SpaceEntity.hpp"
#include <graphics.h>
class SpaceShip;


class Alien: public SpaceEntity
{
    private:
  
    int dy;

    bool start=false; //These attributes are here to check if alien passes the line
    int  oneHit=0;    //These attributes are here to check if alien passes the line

    bool isAlive;     //checks if the alien is alive or not
    SpaceShip *spaceShip;

    public:
	Alien(int _x = 0, int _y = 0, int _width = 0, int _height = 0, int _color = RED, int _dy=1);
	
    bool getAliveStatus() const;

    void setAliveStatus(bool status);


    void  die();
     
	void draw() const;
	void undraw() const;

    void move();
    
    bool CrossesLine(int yLength);
    void decreaseShipLife(SpaceShip *spaceShip);


};


#endif
