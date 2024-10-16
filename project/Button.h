#ifndef _BUTTON_H_
#define _BUTTON_H_

#include<graphics.h>

struct ButtonTool* creatButtonTool
(int x, int y, int w, int h, const char* str, COLORREF inColor, COLORREF outColor);    //创建按钮
void DrawButton(struct ButtonTool* pButton,int text_h,int text_w);                                           //填充按钮
bool isInButton(struct ButtonTool* pButton, ExMessage m);                              //判断鼠标在不在按钮中(有问题)
bool isClickButton(struct ButtonTool* pButton, ExMessage m);                           //判断鼠标有没有点击按钮
bool in(ExMessage m, int x1, int y1, int x2, int y2);                                  //判断鼠标在不在一个矩形内

#endif