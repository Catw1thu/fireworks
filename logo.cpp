#include"logo.h"
#include<iostream>

//void fillellipse(int left,int top,int right,int bottom);
//void solidpolygon(const POINT* points,int num);
//void polybezier(const POINT* points,int num);
//void line(int x1,int y1,int x2,int y2);

void Logo::Drawlogo()//����logo
{
	size(a);
	setColor(RGB(237, 145, 55));
	solidellipse(x - 68, y - 28, x + 28, y + 38);//�� ��Բ
	POINT pts1[] = { {x - 50, y - 40}, {x - 60, y - 15}, {x - 30, y - 25} };//��� ������
	solidpolygon(pts1, 3);
	POINT pts2[] = { {x + 10, y - 40}, {x + 25, y - 5}, {x - 10, y - 25} };//�Ҷ�
	solidpolygon(pts2, 3);
	setBackColor();
	solidellipse(x - 41, y - 11, x - 33, y - 3);//���� ��Բ
	solidellipse(x + 1, y - 11, x - 7, y - 3);//����
	solidellipse(x - 24, y, x - 14, y + 5);//���� ��Բ
	POINT pts[] = { {x - 29, y + 9}, {x - 24,y + 10}, {x - 21, y + 8}, {x - 19,y + 5}, {x - 17, y + 8}, {x - 14,y + 10}, {x - 9,y + 9} };//�� ����������
	polyline(pts, 7);
	line(x - 50, y + 17, x - 36, y + 12);//���� ֱ��
	line(x - 50, y + 7, x - 36, y + 8);
	line(x - 1, y + 12, x + 15, y + 17);
	line(x - 1, y + 8, x + 15, y + 7);
}

void Logo::getinformation(int xx, int yy, COLORREF fill, float a1)//logo��xy���꣬���ɫ������ɫ�����ű���
{
	x = xx;
	y = yy;
	color = fill;
	a = a1;
	Drawlogo();
}

Logo::Logo()
{

}
void Logo::update(int i)
{

}
void Logo::draw(int i)
{

}