#include"area.h"
#include<graphics.h>
#include<string>

std::string info[4][2] = {
	{"何海嘉 202021133038","烟花绽放爱心雨模块"},
	{"杭璐晗 202021004061","logo呈现模块"},
	{"冯劲草 202021004010","小组成员动态呈现模块"},
	{"何芊芊 202021004030","系统整合及界面设计模块"}
};

Area::Area(int x, int y, int length, int height) {
	this->x = x;
	this->y = y;
	this->length = length;
	this->height = height;
	this->textColor= RGB(255, 0, 0); // 字体的初始颜色
}

void Area::draw() {
	setbkmode(TRANSPARENT); // 设置背景透明
}

void Area::show(int id) {
	clearrectangle(this->x, this->y, this->x + this->length, this->y + this->height);
	setbkmode(TRANSPARENT); // 设置背景透明
	settextcolor(this->textColor);
	settextstyle(20, 0, _T("微软雅黑"));
	outtextxy(this->x, this->y,info[id][0].c_str());
	outtextxy(this->x, this->y+22, info[id][1].c_str());
}

bool Area::isin(int x, int y) {
	if ((x >= this->x && x <= (this->x + this->length)) && (y >= this->y && y <= (this->y + this->height)))
		return true;
	return false;
}

void Area::updateColor() {
	// 计算新的颜色值
	BYTE r = GetRValue(this->textColor);
	BYTE g = GetGValue(this->textColor);
	BYTE b = GetBValue(this->textColor);
	r = (r + 1) % 256;
	g = (g + 2) % 256;
	b = (b + 3) % 256;
	this->textColor = RGB(r, g, b);
}
