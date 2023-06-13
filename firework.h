#pragma once
#ifndef FIREWORK_H
#define FIREWORK_H

#include <graphics.h>

#define NUM 13 //在整个屏幕内,最多出现13个烟雾弹

struct Jet
{
	int x, y;//烟花弹的坐标
	int hx, hy;//最高点的坐标
	int height;//高:y-hy
	bool isshot;//是否发射
	DWORD t1, t2, dt;//DWORD是无符号的,相当于unsigned long ,
	//用t1,t2,dt控制速度
	IMAGE Img[2];//存放图片的数组
	byte n : 1;//下标	位段:/:指一个位来存放n
	//位段:(bit-field)是以位为单位来定义结构体(或联合体)中的成员变量所占的空间

};//定义结构体数组

struct Fire
{
	int r;//当前爆炸半径
	int max_r;//爆炸中心距离边缘最大半径
	int x, y;//爆炸中心在窗口的坐标
	int cen_x, cen_y;//爆炸中心相对图片左上角的坐标
	int width;//图片的宽度
	int height;//图片的高度
	int xy[240][240];//储存图片像素点
	bool isshow;//是否显示
	bool isdraw;//是否画出
	DWORD t1, t2, dt;//绽放速度
};

class Firework
{
public:
	Firework();
	void Load();
	void init(int i);
	void Choose(DWORD& t1);
	void shoot();
	void Show(DWORD* pMem);
	void Style(DWORD& st1);
private:
	Jet jet[NUM];
	Fire fire[NUM];
};

#endif // FIREWORK_H