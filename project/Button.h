#ifndef _BUTTON_H_
#define _BUTTON_H_

#include<graphics.h>

struct ButtonTool* creatButtonTool
(int x, int y, int w, int h, const char* str, COLORREF inColor, COLORREF outColor);    //������ť
void DrawButton(struct ButtonTool* pButton,int text_h,int text_w);                                           //��䰴ť
bool isInButton(struct ButtonTool* pButton, ExMessage m);                              //�ж�����ڲ��ڰ�ť��(������)
bool isClickButton(struct ButtonTool* pButton, ExMessage m);                           //�ж������û�е����ť
bool in(ExMessage m, int x1, int y1, int x2, int y2);                                  //�ж�����ڲ���һ��������

#endif