#ifndef _GRAPH_H_
#define _GRAPH_H_

#include<graphics.h>

void Initgraph(int length, int width, COLORREF color, bool batch);  //初始化图窗(batch决定带不带双缓冲)
void Closegraph(bool batch);                                        //关闭窗口(batch决定带不带双缓冲)

#endif 