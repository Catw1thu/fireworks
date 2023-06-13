#pragma once
#include <string>
#include<graphics.h>
#ifndef AREA_H
#define AREA_H
class  Area 
{
private:
	int x;
	int y;
	int length;
	int height;
	COLORREF textColor;
public:
	Area(int x, int y, int length, int height);
	void draw();
	void show(int id);
	bool isin(int x, int y);
	void updateColor();
};

#endif // AREA_H