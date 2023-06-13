#pragma once
#ifndef FIREWORK_H
#define FIREWORK_H

#include <graphics.h>

#define NUM 13 //��������Ļ��,������13������

struct Jet
{
	int x, y;//�̻���������
	int hx, hy;//��ߵ������
	int height;//��:y-hy
	bool isshot;//�Ƿ���
	DWORD t1, t2, dt;//DWORD���޷��ŵ�,�൱��unsigned long ,
	//��t1,t2,dt�����ٶ�
	IMAGE Img[2];//���ͼƬ������
	byte n : 1;//�±�	λ��:/:ָһ��λ�����n
	//λ��:(bit-field)����λΪ��λ������ṹ��(��������)�еĳ�Ա������ռ�Ŀռ�

};//����ṹ������

struct Fire
{
	int r;//��ǰ��ը�뾶
	int max_r;//��ը���ľ����Ե���뾶
	int x, y;//��ը�����ڴ��ڵ�����
	int cen_x, cen_y;//��ը�������ͼƬ���Ͻǵ�����
	int width;//ͼƬ�Ŀ��
	int height;//ͼƬ�ĸ߶�
	int xy[240][240];//����ͼƬ���ص�
	bool isshow;//�Ƿ���ʾ
	bool isdraw;//�Ƿ񻭳�
	DWORD t1, t2, dt;//�����ٶ�
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