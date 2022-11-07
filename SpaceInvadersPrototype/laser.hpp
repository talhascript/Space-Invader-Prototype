#ifndef LASER_H
#define LASER_H

#include <graphics.h>
#include "alien.hpp"
#include "heart.hpp"
#include "SpaceEntity.hpp"

const int ALIENUM = 15;
const int HRTNUM = 3;

class SpaceShip;

class Laser: public SpaceEntity
{
  private:
	int size;
	int speed;
	bool active;
	int color;
	SpaceShip *spaceShip;

	Alien *alien[ALIENUM];
	Heart *heart[HRTNUM];


	void drawHelper(int c) const;
  public:
	Laser(int _x = 0, int _y = 0, int _size = 10, int _color = YELLOW, int _speed = 50);
	bool getActive() const;
	void setSpaceShip(SpaceShip *s);
	void draw() const;
	void undraw() const;
	void move();
	void startPoint();

	bool intersect(int, int, int, int, int, int, int, int);
	bool collide(Alien*);
	bool collide(Heart*);
	
};

#endif
