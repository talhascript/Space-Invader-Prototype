#include <graphics.h>
#include "space_ship.hpp"
#include "Line.hpp"
#include <iostream>
using namespace std;

//? SPACE FORCE ///
//? BY
//? AIMBOT GAMES
//? Md Abu Talha Ibna Riaz Hassan: A20EC3022
//? Iftekhar Uddin Ahmed: A20EC3016
//? Musab Mudathir Altayeb: A20EC4077
//? Tahia Khan: A20EC3030

int main()
{	

	int screenWidth = getmaxwidth();
	int screenHeight = getmaxheight();
	initwindow(screenWidth, screenHeight, "Space Force");


	
    int const ALIENUM = 12;
    int const HRTNUM = 3;

	SpaceShip s1(screenWidth/2, screenHeight-100);
	Line l(0,screenHeight-200,screenWidth);

	Alien list[ALIENUM] ={Alien(20, 0, 60, 60, RED), 
                    Alien(240, 0, 60, 60, RED),
                    Alien(440, 0, 60, 60, RED),
                    Alien(800, 0, 60, 60, RED),
                    Alien(1000, 0, 60, 60, RED),
                    Alien(1200, 0, 60, 60, RED),
                    Alien(600, 110, 60, 60, RED),
                    Alien(1000, 110, 60, 60, RED),
                    Alien(200, 210, 60, 60, RED),
                    Alien(400, 210, 60, 60, RED),
                    Alien(600, 210, 60, 60, RED),
                    Alien(800, 210, 60, 60, RED)};

    Heart list2[HRTNUM] = {Heart(8,110,80,80,BLUE),
                     Heart(890,100,80,80,BLUE),
					Heart(1000, 0, 80, 80,BLUE)};
	
	SpaceEntity *entities[17];

	//Entity 0 to 11 are ALIENS
	for(int i =0; i<ALIENUM; i++){
        entities[i] = &list[i];
    }

	//Entity 12 to 14 are HEARTS
	for(int i = 12; i<15; i++){
        entities[i] = &list2[i-12];
    }

	entities[15] = &l;
	entities[16] = &s1; 


	char ch;


	entities[16]->draw();	// DRAW LINE
	entities[15]->draw();	// DRAW SPACESHIP


	for(int i =0; i<15; i++){
        entities[i]->draw();
		cout<<"draw "<<i<<endl; 
    }
	

	while (true)
	{	

		delay(40);
		s1.doAction();
		entities[15]->draw();



		for(int i =0; i<15; i++){
        entities[i]->move();
    }
    


	for(int i =0; i<ALIENUM; i++){
        if(s1.getBullet().collide(&list[i])){
			list[i].die();
		}
    }

	for(int i =0; i<HRTNUM; i++){
        if(s1.getBullet().collide(&list2[i])){
			list2[i].die();
		}
    }



//losing lives
    for(int i =0; i<ALIENUM; i++){
        if((list[i].CrossesLine(entities[15]->getY())) && (list[i].getAliveStatus() == true)) {
			list[i].decreaseShipLife(&s1);
            break;                    // if 1 red square passes line. ship life decreases by 1
                                     
        }
    }
    

//gaining lives
    for(int i =0; i<HRTNUM; i++){
        if((list2[i].CrossesLine(entities[15]->getY()))   && (list2[i].getAliveStatus()==true) && (s1.getShipLife()<3)) {
			list2[i].increaseShipLife(&s1);
            break;
        } 
    }


   if( (s1.getShipLife())<=0 ) {
	   cout<<"GAME OVER\n";
	   exit(1); }// if 3 or more red square passes, the program closes


		if (kbhit())
		{
			ch = getch();

			if (ch == 27)
				break;
			else if (ch == ' ')
				s1.shoot();
			else if (ch == 0)
			{
				ch = getch();

				switch (ch)
				{
				case 75:// ascii code for left arrow
					s1.move(-20);
					break;

				case 77:// ascii code for right arrow
					s1.move(20);
					break;
				}
			}
		}
	}
	return 0;
}
