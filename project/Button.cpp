#include<graphics.h>
#include<assert.h>
#include"Global.h"
struct ButtonTool
{
	int x;
	int y;
	int w;
	int h;
	COLORREF curColor;    //������ɫ
	COLORREF inColor;
	COLORREF outColor;
	char* text;          //����
};
//������ť
struct ButtonTool* creatButtonTool(int x, int y, int w, int h, const char* str, COLORREF inColor, COLORREF outColor)
{
	struct ButtonTool* pButton = (struct ButtonTool*)malloc(sizeof(struct ButtonTool));
	assert(pButton);
	pButton->x = x;
	pButton->y = y;
	pButton->w = w;
	pButton->h = h;
	pButton->inColor = inColor;
	pButton->outColor = outColor;
	pButton->curColor = outColor;
	size_t textlength = strlen(str) + 1;
	pButton->text = (char*)malloc(sizeof(char*) * textlength);
	assert(pButton->text);
	strcpy_s(pButton->text, textlength, str);
	return pButton;
}
//��䰴ť
void DrawButton(struct ButtonTool* pButton,int text_h,int text_w)
{
	//������
	setlinestyle(PS_ENDCAP_ROUND, 1);
	setlinecolor(BLACK); 
	setfillcolor(pButton->curColor);
	fillrectangle(pButton->x, pButton->y, pButton->x + pButton->w, pButton->y + pButton->h);
	setlinecolor(_color_);
	//д����
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);    //������ɫ
	settextstyle(text_h, text_w, "����");
	//���־���
	int textw = textwidth(pButton->text);
	int texth = textheight(pButton->text);
	int xx = pButton->x + (pButton->w - textw) / 2;
	int yy = pButton->y + (pButton->h - texth) / 2;
	outtextxy(xx, yy, pButton->text);
	setlinestyle(PS_ENDCAP_ROUND, _size_);
}
//�ж�����ڲ��ڰ�ť��(������)
bool isInButton(struct ButtonTool* pButton, ExMessage m)
{
	if (m.x > pButton->x && m.x<pButton->x + pButton->w && m.y>pButton->y && m.y < pButton->y + pButton->h)
	{
		pButton->curColor = pButton->inColor;
		return true;
	}
	pButton->curColor = pButton->outColor;
	return false;
}
//�ж������û�е����ť
bool isClickButton(struct ButtonTool* pButton, ExMessage m)
{
	if (isInButton(pButton, m) && m.message == WM_LBUTTONDOWN)
	{
		return true;
	}
	return false;
}
//�ж��Ƿ���һ��������
bool in(ExMessage m,int x1, int y1, int x2, int y2)
{
	if (m.x > x1 && m.x<x2 && m.y>y1 && m.y < y2)return true;
	return false;
}