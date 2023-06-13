#include<stdio.h>
#include<graphics.h>//之前要先安装EasyX,不然导入这个包会报错
#include<conio.h>
#include<math.h>
#include<time.h>//随机数
#include"firework.h"
#include"area.h"
#include<mmsystem.h>//多媒体设备接口的头文件
#include<string>
#include"logo.h"
#pragma comment(lib,"winmm.lib")//Media control interface
//这条指令和你在工程中添加"winmm.lib"的功能一样，告诉编译器要导入winmm库

#define NUM 13 //在整个屏幕内,最多出现13个烟雾弹
void Welcome();//进入程序运行界面
void write(DWORD&);
void clear(DWORD*);

int main()
{
	srand((unsigned int)time(NULL));		//为了得到不一样的随机数

	initgraph(1000, 600);//初始化一个窗口
	
	Welcome();
	
	DWORD t1 = timeGetTime();			// 筛选烟花计时
	DWORD st1 = timeGetTime();			// 播放花样计时
	DWORD tm = timeGetTime();			//字体播放计时

	Firework* firework = new Firework();

	DWORD TC;

	DWORD* pMem = GetImageBuffer();		// 获取窗口显存指针,对每个像素点进行操作
	
	firework->Load();								// 将烟花图片信息加载进相应结构中
	
	Area lefttopArea(0, 0, 100, 100);
	Area righttopArea(840, 0, 160, 50);
	Area rightbottomArea(850, 334, 150, 226);

	MOUSEMSG m;

	clearrectangle(0, 0, 1000, 600);

	Logo logo;

	IMAGE img;
	loadimage(&img, "./file/couple.jpg", 150, 266);

	BeginBatchDraw();					// 开始批量绘图

	int x = 0, y = 0;
	
	while (!_kbhit())
	{
		righttopArea.updateColor();
		Sleep(10);
		clear(pMem);
		TC = timeGetTime();
		if (TC - t1 > 0)
		{
			logo.getinformation(80, 50, RED, 1);
			putimage(850, 334, &img);
			righttopArea.draw();
		}
		firework->Choose(t1);
		firework->shoot();
		firework->Show(pMem);
		firework->Style(st1);
		FlushBatchDraw();	// 显示前面的所有绘图操作
		if (MouseHit()) {
			m = GetMouseMsg();
			x = m.x, y = m.y;
		}
		if (lefttopArea.isin(x, y)) {
			righttopArea.show(1);
		}
		else if (righttopArea.isin(x, y)) {
			righttopArea.show(2);
		}
		else if (rightbottomArea.isin(x, y)) {
			righttopArea.show(3);
		}
		else {
			righttopArea.show(0);
		}
	}
	
	_getch();
	closegraph();
	return 0;
}
void Welcome()//程序运行一开始进入的界面
{
	IMAGE bg;
	loadimage(&bg, "./file/bg.jpg");
	putimage(0, 0, &bg);
	mciSendString("open ./file/C418-Sweden.mp3 alias music ", 0, 0, 0);//alias取别名
	mciSendString("play music repeat", 0, 0, 0);
	setbkmode(TRANSPARENT);
	settextstyle(35, 0, "楷体");
	settextcolor(WHITE);
	Sleep(2000);
	outtextxy(100, 150, "让最美的烟花带给大家最真挚的祝福");
	Sleep(2000);
	outtextxy(115, 200, "万世鸿宴许盛愿,烟火遍野兆新年");
	Sleep(2000);
	outtextxy(25, 250, "烟火向星辰,所愿皆成真,年年顺意，岁岁欢愉");
	Sleep(2000);
	outtextxy(50, 300, "所求皆如愿,所行皆坦途,多喜乐，长安宁");
	Sleep(2000);
	outtextxy(215, 350, "愿我们2023下半年");
	Sleep(2000);
	outtextxy(165, 400, "所得皆所愿，所行亦无憾");
	Sleep(2000);
	outtextxy(165, 450, "岁岁长喜乐，万事皆顺意");
}
void clear(DWORD* pMem)
{
	pMem = GetImageBuffer();		// 获取窗口显存指针,对每个像素点进行操作
	// 随机选择 4000 个像素点擦除
	for (int clr = 0; clr < 1000; clr++)
	{
		for (int j = 0; j < 2; j++)
		{
			int px1 = rand() % 1000;
			int py1 = rand() % 600;

			if (py1 < 599)				// 防止越界
				pMem[py1 * 1000 + px1] = pMem[py1 * 1000 + px1 + 1] = BLACK;	// 对显存赋值擦出像素点
		}
	}//对像素点进行擦除
}