#include<stdio.h>
#include<graphics.h>//֮ǰҪ�Ȱ�װEasyX,��Ȼ����������ᱨ��
#include<conio.h>
#include<math.h>
#include<time.h>//�����
#include"firework.h"
#include"area.h"
#include<mmsystem.h>//��ý���豸�ӿڵ�ͷ�ļ�
#include<string>
#include"logo.h"
#pragma comment(lib,"winmm.lib")//Media control interface
//����ָ������ڹ��������"winmm.lib"�Ĺ���һ�������߱�����Ҫ����winmm��

#define NUM 13 //��������Ļ��,������13������
void Welcome();//����������н���
void write(DWORD&);
void clear(DWORD*);

int main()
{
	srand((unsigned int)time(NULL));		//Ϊ�˵õ���һ���������

	initgraph(1000, 600);//��ʼ��һ������
	
	Welcome();
	
	DWORD t1 = timeGetTime();			// ɸѡ�̻���ʱ
	DWORD st1 = timeGetTime();			// ���Ż�����ʱ
	DWORD tm = timeGetTime();			//���岥�ż�ʱ

	Firework* firework = new Firework();

	DWORD TC;

	DWORD* pMem = GetImageBuffer();		// ��ȡ�����Դ�ָ��,��ÿ�����ص���в���
	
	firework->Load();								// ���̻�ͼƬ��Ϣ���ؽ���Ӧ�ṹ��
	
	Area lefttopArea(0, 0, 100, 100);
	Area righttopArea(840, 0, 160, 50);
	Area rightbottomArea(850, 334, 150, 226);

	MOUSEMSG m;

	clearrectangle(0, 0, 1000, 600);

	Logo logo;

	IMAGE img;
	loadimage(&img, "./file/couple.jpg", 150, 266);

	BeginBatchDraw();					// ��ʼ������ͼ

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
		FlushBatchDraw();	// ��ʾǰ������л�ͼ����
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
void Welcome()//��������һ��ʼ����Ľ���
{
	IMAGE bg;
	loadimage(&bg, "./file/bg.jpg");
	putimage(0, 0, &bg);
	mciSendString("open ./file/C418-Sweden.mp3 alias music ", 0, 0, 0);//aliasȡ����
	mciSendString("play music repeat", 0, 0, 0);
	setbkmode(TRANSPARENT);
	settextstyle(35, 0, "����");
	settextcolor(WHITE);
	Sleep(2000);
	outtextxy(100, 150, "���������̻������������ֿ��ף��");
	Sleep(2000);
	outtextxy(115, 200, "����������ʢԸ,�̻��Ұ������");
	Sleep(2000);
	outtextxy(25, 250, "�̻����ǳ�,��Ը�Գ���,����˳�⣬���껶��");
	Sleep(2000);
	outtextxy(50, 300, "�������Ը,���н�̹;,��ϲ�֣�������");
	Sleep(2000);
	outtextxy(215, 350, "Ը����2023�°���");
	Sleep(2000);
	outtextxy(165, 400, "���ý���Ը���������޺�");
	Sleep(2000);
	outtextxy(165, 450, "���곤ϲ�֣����½�˳��");
}
void clear(DWORD* pMem)
{
	pMem = GetImageBuffer();		// ��ȡ�����Դ�ָ��,��ÿ�����ص���в���
	// ���ѡ�� 4000 �����ص����
	for (int clr = 0; clr < 1000; clr++)
	{
		for (int j = 0; j < 2; j++)
		{
			int px1 = rand() % 1000;
			int py1 = rand() % 600;

			if (py1 < 599)				// ��ֹԽ��
				pMem[py1 * 1000 + px1] = pMem[py1 * 1000 + px1 + 1] = BLACK;	// ���Դ渳ֵ�������ص�
		}
	}//�����ص���в���
}