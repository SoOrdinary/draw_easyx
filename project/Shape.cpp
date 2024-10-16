#include<math.h>
#include"Shape.h"
//保存
void Save::draw(ExMessage m)
{
	saveimage("picture/my.png");
}
//打开
void Save_as::draw(ExMessage m)
{
	loadimage(&picture, "picture/my.png");
	putimage(0, 0, &picture);
}
//选择1
void Choice1::dfs(int x, int y)
{
	//退出条件
	if (counter >= MAX_POINTS || getpixel(x, y) == WHITE)
	{
		return;
	}
	//标记为已访问
	putpixel(x, y, WHITE);
	//记录数组
	points[counter].x = x;
	points[counter].y = y;
	counter++;
	//递归遍历
	dfs(x - 1, y);
	dfs(x + 1, y);
	dfs(x, y - 1);
	dfs(x, y + 1);
}
void Choice1::draw(ExMessage m)
{
	if (judg == 1 && m.x != x2 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		counter = 0;
		memset(points, 0, sizeof(points));
		judg = 2;
		dfs(m.x, m.y);
	}
	if (judg == 2 && m.x != x1 && m.message == WM_LBUTTONDOWN)
	{
		x2 = m.x;
		y2 = m.y;
		for (counter = 0; counter <= MAX_POINTS && points[counter].x != 0; counter++)
		{
			setlinestyle(PS_ENDCAP_ROUND, 1);
			line(points[counter].x + (x2 - x1), points[counter].y + (y2 - y1), points[counter].x + (x2 - x1), points[counter].y + (y2 - y1));
		}
		setlinestyle(PS_ENDCAP_ROUND, 5);
		judg = 1;
	}
}
//选择2
int Choice2::df_Rectangle(ExMessage m)
{
	for (int i = 0; i <= num_rectangle; i++)
	{
		if (m.x >= rec[i].x && m.x <= (rec[i].x+ rec[i].width) && m.y >= rec[i].y && m.y <= (rec[i].y +rec[i].high))
		{
			return i;
		}
	}
	return 0;
}
int Choice2::df_Circle(ExMessage m)
{
	for (int i = 0; i <= num_circle; i++)
	{
		if ((m.x - cir[i].x) * (m.x - cir[i].x) + (m.y - cir[i].y) * (m.y - cir[i].y) <= (cir[i].r) * (cir[i].r))
		{
			return i;
		}
	}
	return 0;
}
void Choice2::change(ExMessage m,int re_x,int re_y)
{
	counter = df_Rectangle(m);
	if (counter != 0)
	{
		setlinecolor(WHITE);
		rectangle(rec[counter].x, rec[counter].y, rec[counter].x + rec[counter].width, rec[counter].y + rec[counter].high);
		rec[counter].x += re_x;
		rec[counter].y += re_y;
		setlinecolor(BLACK);
		rectangle(rec[counter].x, rec[counter].y, rec[counter].x+ rec[counter].width, rec[counter].y+ rec[counter].high);
		return;
	}
	counter = df_Circle(m);
	if (counter != 0)
	{
		setlinecolor(WHITE);
		circle(cir[counter].x, cir[counter].y, cir[counter].r);
		cir[counter].x += re_x;
		cir[counter].y += re_y;
		setlinecolor(BLACK);
		circle(cir[counter].x, cir[counter].y, cir[counter].r);
		return;
	}
}
void Choice2::draw(ExMessage m)
{
	if (m.x != x2 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		isDown = true;
	}
	if (m.message == WM_LBUTTONUP)
	{
		isDown = false;
	}
	if (m.x != x1 && isDown==true && m.message == WM_MOUSEMOVE)
	{
		x2 = m.x;
		y2 = m.y;
		change(m, x2 - x1, y2 - y1);
		x1 = m.x;
		y1 = m.y;
	}
}
//清除
void Clear::draw(ExMessage m)
{
	cleardevice();
	num_rectangle = 0;
	num_circle = 0;
}
//退出
void Quit::draw(ExMessage m)
{
	project = false;
}
//自由线
void Line::draw(ExMessage m)
{
	//鼠标左键按下
	if (m.message == WM_LBUTTONDOWN)
	{
		x = m.x;
		y = m.y;
		isDown = true;
		line(x, y,m.x,m.y);
	}
	//鼠标左键弹起
	if (m.message == WM_LBUTTONUP)
	{
		isDown = false;
	}
	//鼠标移动+左键按下
	if (m.message == WM_MOUSEMOVE && isDown == true)
	{
		line(x, y, m.x, m.y);
	}
	x = m.x;
	y = m.y;
}
//直线
void Straight_Line::draw(ExMessage m)
{
	if (judg == 1 && m.x != x2 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		judg = 2;
		line(x1, y1, x1, y1);
	}
	if (judg == 2 && m.x != x1 && m.message == WM_LBUTTONDOWN)
	{
		x2 = m.x;
		y2 = m.y;
		line(x1, y1, x2, y2);
		judg = 1;
	}
}
//矩形
void Rectangle_::draw(ExMessage m)
{
	if (judg == 1 && m.x != x2 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		judg = 2;
		line(x1, y1, x1, y1);
	}
	if (judg == 2 && m.x != x1 && m.message == WM_LBUTTONDOWN)
	{
		x2 = m.x;
		y2 = m.y;
		num_rectangle++;
		rectangle(rec[num_rectangle].x = x1, rec[num_rectangle].y = y1, x2, y2);
		rec[num_rectangle].width = x2 - x1;
		rec[num_rectangle].high = y2 - y1;
		judg = 1;
	}
}
//圆
void Circle::draw(ExMessage m)
{
	if (judg == 1 && m.x != x2 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		judg = 2;
		line(x1, y1, x1, y1);
	}
	if (judg == 2 && m.x != x1 && m.message == WM_LBUTTONDOWN)
	{
		x2 = m.x;
		y2 = m.y;
		r = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		num_circle++;
		setlinecolor(WHITE);
		line(x1, y1, x1, y1);
		setlinecolor(_color_);
		circle(cir[num_circle].x = x1, cir[num_circle].y = y1, cir[num_circle].r = r);
		judg = 1;
	}
}
//多边形
void Polygon_::draw(ExMessage m)
{
	if (judg == 1 && m.message == _draw_start_)
	{
		points[0].x = m.x;
		points[0].y = m.y;
		judg = 2;
		line(points[0].x, points[0].y, points[0].x, points[0].y);
	}
	if (judg == 2 && m.x != points[step].x && m.message == _draw_next_)
	{
		step++;
		points[step].x = m.x;
		points[step].y = m.y;
		line(points[step-1].x, points[step-1].y, points[step].x, points[step].y);
	}
	if (m.message == _draw_finish_)
	{
		line(points[step].x, points[step].y, points[0].x, points[0].y);
		step = 0;
		judg = 1;
	}
}