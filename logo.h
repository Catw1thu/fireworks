#pragma once
#pragma once
#include <graphics.h>
#include <conio.h>
#include "shape.h"
#include <iostream>
using namespace std;
class Logo :public shape
{
private:
	int x;
	int y;
	COLORREF color;
	COLORREF colorback;
	float a;
	void setColor(COLORREF color)//logo颜色
	{
		setfillcolor(color);
	}
	void setBackColor()//背景颜色
	{
		setfillcolor(colorback);
	}
	void size(float a)//缩放比例
	{
		setaspectratio(a, a);
	}
	void Drawlogo();


public:
	Logo();
	//void Drawlogo();
	void  update(int);
	void draw(int);
	void getinformation(int, int, COLORREF, float);//logo的xy坐标，填充色，背景色，缩放比例	
};