#include<graphics.h>
#include"Global.h"

const char* operate_[] = { "�������","���˫��","�м�����","�м�˫��","�Ҽ�����","�Ҽ�˫��" };
const char* color_[] = { "��ɫ","��ɫ","��ɫ","��ɫ"};
const char* way_[] = { "���ʽ","����ʽ"};

void drawstate(Set* color,Set*start, Set*next, Set*finish)
{
	int x = 830, y = 525;
	setlinecolor(RGB(236, 244, 255));
	setfillcolor(RGB(204, 213, 240));
	fillrectangle(x, y, 1040, 800);
	x += 10; y += 5;
	outtextxy(x, y, "��ǰ״̬:");
	int w = x+112, v = y;
	//����
	outtextxy(x, y += 25, "���ʴ�С---");
	outtextxy(x, y += 25, "��ǰ��ɫ---");
	outtextxy(x, y += 25, "��ʼ����---");
	outtextxy(x, y += 25, "��������---");
	outtextxy(x, y += 25, "��������---");
	outtextxy(x, y += 25, "��������---");
	outtextxy(x, y += 25, "Բ�ĸ���---");
	outtextxy(x, y += 25, "���Ʒ�ʽ---");
	//״̬
	outtextxy(w, v += 25, _size_+48);
	outtextxy(w, v += 25, color_[color->judg]);
	outtextxy(w, v += 25, operate_[start->judg]);
	outtextxy(w, v += 25, operate_[next->judg]);
	outtextxy(w, v += 25, operate_[finish->judg]);
	outtextxy(w, v += 25, num_rectangle+48);
	outtextxy(w, v += 25, num_circle+48);
	outtextxy(w, v += 25, way_[way]);

	outtextxy(960,770,"draw6.0");
	setlinecolor(_color_);
}
