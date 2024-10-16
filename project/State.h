#include<graphics.h>
#include"Global.h"

const char* operate_[] = { "左键按下","左键双击","中键按下","中键双击","右键按下","右键双击" };
const char* color_[] = { "黑色","红色","绿色","蓝色"};
const char* way_[] = { "点击式","滑动式"};

void drawstate(Set* color,Set*start, Set*next, Set*finish)
{
	int x = 830, y = 525;
	setlinecolor(RGB(236, 244, 255));
	setfillcolor(RGB(204, 213, 240));
	fillrectangle(x, y, 1040, 800);
	x += 10; y += 5;
	outtextxy(x, y, "当前状态:");
	int w = x+112, v = y;
	//类型
	outtextxy(x, y += 25, "画笔大小---");
	outtextxy(x, y += 25, "当前颜色---");
	outtextxy(x, y += 25, "开始操作---");
	outtextxy(x, y += 25, "继续操作---");
	outtextxy(x, y += 25, "结束操作---");
	outtextxy(x, y += 25, "长方体数---");
	outtextxy(x, y += 25, "圆的个数---");
	outtextxy(x, y += 25, "绘制方式---");
	//状态
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
