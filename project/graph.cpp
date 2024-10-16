#include<iostream>
#include<graphics.h>
using namespace std;

void Initgraph(int length,int width,COLORREF color,bool batch)
{
	initgraph(length, width, EW_DBLCLKS);               //�������ڣ�Ĭ��Ϊ��
	setbkcolor(color);                  //���ñ���ɫ
	cleardevice();
	if (batch) { BeginBatchDraw(); }
}

void Closegraph(bool batch)
{
	if (batch) { EndBatchDraw(); }
	closegraph();
}