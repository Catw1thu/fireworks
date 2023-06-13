#pragma once
#pragma once
#include<string>
#include <conio.h>
#include <graphics.h>
#include <easyx.h>
#include<iomanip>
#include<ctime>
#include <time.h>
#include <cstdlib> 
#include<vector>
#include <iostream>
#include"shape.h"

using namespace std;



#ifndef STAR_H_
#define STAR_H_



class star :public shape
{
public:
	star(int);
	~star();
	//void setStar(int);
	void update(int);
	virtual void draw(int);
private:
	int sum;
	vector<shapes>stars;
};

#endif