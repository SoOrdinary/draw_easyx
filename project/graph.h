#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<graphics.h>

void Initgraph(int length, int width, COLORREF color, bool batch);  //��ʼ��ͼ��(batch����������˫����)
void Closegraph(bool batch);                                        //�رմ���(batch����������˫����)

#endif 