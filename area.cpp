#include"area.h"
#include<graphics.h>
#include<string>

std::string info[4][2] = {
	{"�κ��� 202021133038","�̻����Ű�����ģ��"},
	{"����� 202021004061","logo����ģ��"},
	{"�뾢�� 202021004010","С���Ա��̬����ģ��"},
	{"��ܷܷ 202021004030","ϵͳ���ϼ��������ģ��"}
};

Area::Area(int x, int y, int length, int height) {
	this->x = x;
	this->y = y;
	this->length = length;
	this->height = height;
	this->textColor= RGB(255, 0, 0); // ����ĳ�ʼ��ɫ
}

void Area::draw() {
	setbkmode(TRANSPARENT); // ���ñ���͸��
}

void Area::show(int id) {
	clearrectangle(this->x, this->y, this->x + this->length, this->y + this->height);
	setbkmode(TRANSPARENT); // ���ñ���͸��
	settextcolor(this->textColor);
	settextstyle(20, 0, _T("΢���ź�"));
	outtextxy(this->x, this->y,info[id][0].c_str());
	outtextxy(this->x, this->y+22, info[id][1].c_str());
}

bool Area::isin(int x, int y) {
	if ((x >= this->x && x <= (this->x + this->length)) && (y >= this->y && y <= (this->y + this->height)))
		return true;
	return false;
}

void Area::updateColor() {
	// �����µ���ɫֵ
	BYTE r = GetRValue(this->textColor);
	BYTE g = GetGValue(this->textColor);
	BYTE b = GetBValue(this->textColor);
	r = (r + 1) % 256;
	g = (g + 2) % 256;
	b = (b + 3) % 256;
	this->textColor = RGB(r, g, b);
}
