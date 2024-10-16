#include<math.h>
#include"Shape2.h"
//直线
void Straight_Line2::draw(ExMessage m)
{
	if (m.x != x1 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		saveimage("picture/Buffer.png");
		line(x1, y1, x1, y1);
		isDown = true;
	}
	if (m.x != x2 && isDown == true && m.message == WM_MOUSEMOVE)
	{
		x2 = m.x;
		y2 = m.y;
		cleardevice();
		loadimage(&picture, "picture/Buffer.png");
		putimage(0, 0, &picture);
		line(x1, y1, x2, y2);
	}
	if (m.message == WM_LBUTTONUP)
	{
		isDown = false;
	}
}
//矩形
void Rectangle_2::draw(ExMessage m)
{
	if (m.x != x1 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		num_rectangle++;
		saveimage("picture/Buffer.png");
		line(x1, y1, x1, y1);
		isDown = true;
	}
	if (m.x != x2 && isDown == true && m.message == WM_MOUSEMOVE)
	{
		x2 = m.x;
		y2 = m.y;
		cleardevice();
		loadimage(&picture, "picture/Buffer.png");
		putimage(0, 0, &picture);
		rectangle(rec[num_rectangle].x = x1, rec[num_rectangle].y = y1, x2, y2);
		rec[num_rectangle].width = x2 - x1;
		rec[num_rectangle].high = y2 - y1;
	}
	if (m.message == WM_LBUTTONUP)
	{
		isDown = false;
	}
}
//圆
void Circle2::draw(ExMessage m)
{
	if (m.x != x1 && m.message == WM_LBUTTONDOWN)
	{
		x1 = m.x;
		y1 = m.y;
		num_circle++;
		saveimage("picture/Buffer.png");
		line(x1, y1, x1, y1);
		isDown = true;
	}
	if (m.x != x2 && isDown == true && m.message == WM_MOUSEMOVE)
	{
		x2 = m.x;
		y2 = m.y;
		r = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		cleardevice();
		loadimage(&picture, "picture/Buffer.png");
		putimage(0, 0, &picture);
		circle(cir[num_circle].x = x1, cir[num_circle].y = y1, cir[num_circle].r = r);
	}
	if (m.message == WM_LBUTTONUP)
	{
		isDown = false;
	}
}
//多边形
void Polygon_2::draw(ExMessage m)
{
	if (m.x != points[step].x && m.message == WM_LBUTTONDOWN)
	{
		if (step == 0)
		{
			points[0].x = m.x;
			points[0].y = m.y;
			saveimage("picture/Buffer.png");
		}
		judg = 2;
		step++;
		points[step].x = m.x;
		points[step].y = m.y;
		saveimage("picture/Buffer.png");
		line(points[step - 1].x, points[step - 1].y, points[step].x, points[step].y);
		isDown = true;
	}
	if (m.x != points[step].x && judg == 2 && isDown == true && m.message == WM_MOUSEMOVE)
	{
		points[step].x = m.x;
		points[step].y = m.y;
		cleardevice();
		loadimage(&picture, "picture/Buffer.png");
		putimage(0, 0, &picture);
		line(points[step - 1].x, points[step - 1].y, points[step].x, points[step].y);
	}
	if (m.message == WM_LBUTTONUP)
	{
		isDown = false;
	}
	if (m.message == WM_RBUTTONDOWN)
	{
		line(points[step].x, points[step].y, points[0].x, points[0].y);
		step = 0;
		judg = 1;
	}
}
//多边形(自动生成最后一条边，右键结束，略有问题)
/*void Polygon_2::draw(ExMessage m)
{
	if (m.x != points[step].x && m.message == WM_LBUTTONDOWN)
	{
		if(step==0)
		{
			points[0].x = m.x;
			points[0].y = m.y;
			saveimage("picture/Buffer.png");
		}
		judg = 2;
		step++;
		points[step].x = m.x;
		points[step].y = m.y;
		cleardevice();
		loadimage(&picture, "picture/Buffer.png");
		putimage(0, 0, &picture);
		line(points[step - 1].x, points[step - 1].y, points[step].x, points[step].y);
		line(points[step].x, points[step].y, points[0].x, points[0].y);
		isDown = true;
	}
	if (m.x != points[step].x && judg==2 && isDown == true && m.message == WM_MOUSEMOVE)
	{
		points[step].x = m.x;
		points[step].y = m.y;
		cleardevice();
		loadimage(&picture, "picture/Buffer.png");
		putimage(0, 0, &picture);
		line(points[step-1].x, points[step-1].y, points[step].x, points[step].y);
		line(points[step].x, points[step].y, points[0].x, points[0].y);
	}
	if (m.message == WM_LBUTTONUP)
	{
		if (step != 0)
		{
			cleardevice();
			loadimage(&picture, "picture/Buffer.png");
			putimage(0, 0, &picture);
			line(points[step - 1].x, points[step - 1].y, points[step].x, points[step].y);
			saveimage("picture/Buffer.png");
			line(points[step].x, points[step].y, points[0].x, points[0].y);
		}
		isDown = false;
	}
	if (m.message == WM_RBUTTONDOWN)
	{
		step = 0;
		judg = 1;
	}
}*/