#include<iostream>
#include<graphics.h>
using namespace std;

void Initgraph(int length,int width,COLORREF color,bool batch)
{
	initgraph(length, width, EW_DBLCLKS);               //创建窗口，默认为黑
	setbkcolor(color);                  //设置背景色
	cleardevice();
	if (batch) { BeginBatchDraw(); }
}

void Closegraph(bool batch)
{
	if (batch) { EndBatchDraw(); }
	closegraph();
}