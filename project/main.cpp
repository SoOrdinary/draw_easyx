#include<graphics.h>
#include"graph.h"
#include"Shape.h"
#include"Shape2.h"
#include"set.h"
#include"state.h"

int main()
{
	//初始化
	Initgraph(1040, 800,WHITE,true);
	//线的样式
    setlinestyle(_size_);
	setlinecolor(_color_);
	ExMessage m;
	bool menu1 = false, menu2 = false;
	int mode = 1, i = 7, j = 0;
	//上菜单功能
	Shape* ptr1[] =
	{
		nullptr,
		new Save,new Save_as,new Clear,new Quit,new Choice1,new Choice2,new Line,
		new Straight_Line,new Rectangle_,new Circle,new Polygon_,
		nullptr
	};
	//其他绘制方法
	Shape_other* ptr[][6] =
	{
		{
			nullptr,
			new Straight_Line2,new Rectangle_2 ,new Circle2,new Polygon_2,
			nullptr
		}
	};
	//下菜单功能
    Set* ptr2[] =
    {
        nullptr,
        new draw_size1,new draw_size2,new change_color,new draw_start,new draw_next,new draw_finish,new paint_way,
		nullptr
	};
	//主程序
	while (project)
	{
		peekmessage(&m, EX_MOUSE);
		//画图
		if (in(m, 0, 35, 1040, 765))
		{
			if (way == 0 || mode == 7 )ptr1[mode]->draw(m);
			else ptr[way-1][mode-7]->draw(m);
		}
		//上菜单
		if (in(m, 0, 0, 1040, 50)||menu1==false)
		{
			for (j = 1; ptr1[j]; j++)
			{
				i = ptr1[j]->drawButton(m);
				if (i) mode = i;
			}
			if (mode < 5)
			{
				ptr1[mode]->draw(m);
				menu2 = false;
				mode = 7;
			}
			menu1 = true;
		}
		//下菜单
		if (in(m, 0, 750, 1040, 800)||menu2==false)
		{
			for (j = 1; ptr2[j]; j++)
			{
				i = ptr2[j]->drawButton(m);
				if (i) ptr2[i]->draw(m);
			}
			menu2 = true;
		}
		//实时更新状态栏
		drawstate(ptr2[3],ptr2[4],ptr2[5],ptr2[6]);
		FlushBatchDraw();
	}
    //内存释放
	for (j = 1; ptr1[j]; j++)
	{
		delete(ptr1[j]);
		ptr1[j] = nullptr;
	}
	for (j = 1; ptr2[j]; j++)
	{
		delete(ptr2[j]);
		ptr2[j] = nullptr;
	}
	Closegraph(true);
	return 0;
}