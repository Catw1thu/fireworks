#include "star.h"

star::star(int number) :sum(number)//, shape(InvalidColor)
{
	int angleChange;
	int colorChange3;
	int colorChange2;
	for (int i = 0; i < sum; i++)
	{
		stars.push_back(shapes{});
		stars[i].x = 5 + rand() % 990;
		stars[i].y = 5 + rand() % 710;
		stars[i].angle = rand() % 72;
		stars[i].r = 2 + rand() % 20;
		angleChange = rand() % 100;
		double a = pi / 2 + stars[i].angle + angleChange;
		for (int t = 0; t < 5; t++)
		{
			stars[i].place[t].x = int(stars[i].x + cos(a) * stars[i].r);
			stars[i].place[t].y = int(stars[i].y - sin(a) * stars[i].r);
			a += pi * 4 / 5;
		}
		colorChange3 = rand() % 255;
		colorChange2 = 200 + rand() % 55;
		stars[i].color = RGB(static_cast<BYTE>(colorChange2), static_cast<BYTE>(colorChange2), static_cast<BYTE>(colorChange3));


	}
}

star::~star()
{
}

void star::update(int time)
{

	int colorChange3;
	int colorChange2;
	int angleChange;

	for (int i = 0; i < sum; i++)
	{
		/*
		 if (time % 3 == 0)
		{
			angleChange = rand() % 100;

			if (time % 100 == 0)
			{
				stars[i].x = 5 + rand() % 890;
				stars[i].y = 5 + rand() % 510;
			}
			double a = pi / 2 + stars[i].angle + angleChange;
			if (time % 2)
				stars[i].r++;
			else stars[i].r--;

			for (int t = 0; t < 5; t++)
			{
				stars[i].place[t].x = int(stars[i].x + cos(a) * stars[i].r);
				stars[i].place[t].y = int(stars[i].y - sin(a) * stars[i].r);
				a += pi * 4 / 5;
			}


			
		}
		*/
		colorChange3 = rand() % 255;
		colorChange2 = 200 + rand() % 55;
		stars[i].color = RGB(static_cast<BYTE>(colorChange2), static_cast<BYTE>(colorChange2), static_cast<BYTE>(colorChange3));

		draw(i);
	}



}

void star::draw(int i)
{
	setpolyfillmode(WINDING);
	setfillcolor(stars[i].color);
	// »æÖÆÎå½ÇÐÇ(ÎÞ±ß¿ò)
	solidpolygon(stars[i].place, 5);
}

