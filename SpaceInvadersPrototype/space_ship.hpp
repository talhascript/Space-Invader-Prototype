#ifndef SPACE_SHIP_H
#define SPACE_SHIP_H

#include <graphics.h>
#include "laser.hpp"
#include "SpaceEntity.hpp"

#define MAXBULLET 10

class Laser; 

class SpaceShip: public SpaceEntity
{
private:
	
	int shipLife; // max value is 3

	Laser bullets[MAXBULLET];

	void drawHelper(int c) const; //helper method

public:
	SpaceShip(int _x = 0, int _y = 0, int _width = 150, int _height = 100, int _color = BLUE);
	
	void shoot();
	void draw() const;
	void undraw() const;
	void move(int dx);
	void doAction(); // moves bullets from the spaceship

	int getShipLife() const;
	

	void AddShipLife();
	void SubtractShipLife();

	Laser getBullet();
	void setShipLife(int);
	
};

#endif
