#ifndef _SHAPE_H_
#define _SHAPE_H_

#include<graphics.h>
#include"Button.h"
#include"Global.h"
#define MAX_POINTS 10000
#define MAX_POLYGON 100

class Shape
{
public:
    Shape(int mode, int x0, int y0, const char* str) :mode(mode), x0(x0), y0(y0), str(str) {}
    ~Shape()
    {
        free(menuButton);
        menuButton = nullptr;
    }
public:
    bool isDown=false;
    int x0, y0;
    int judg = 1;
    int mode;
    const char* str;
    struct ButtonTool* menuButton = creatButtonTool(x0, y0, 80, 35, str, RGB(236, 244, 255), RGB(204, 213, 240));
    int drawButton(ExMessage m) 
    { 
        DrawButton(menuButton,20,10); 
        if (isClickButton(menuButton, m))
            return mode;
        else 
            return 0;
    };
	virtual void draw(ExMessage m)=0;
};
//保存
class Save : public Shape
{
public:
    int x, y;
    IMAGE picture;
    Save():Shape(1,0,0,"保存") {}
    void draw(ExMessage m) override;
};
//打开
class Save_as : public Shape
{
public:
    int x, y;
    IMAGE picture;
    Save_as() :Shape(2,80, 0, "打开") {}
    void draw(ExMessage m) override;
};
//选择1
class Choice1 : public Shape
{
public:
    struct point
    {
        int x;
        int y;
    }points[MAX_POINTS];
    int x1, y1, x2, y2;
    int counter=0;
    Choice1() :Shape(5,160, 0, "选择1") {}
    void dfs(int x, int y);
    void draw(ExMessage m) override;
};
//选择2
class Choice2 : public Shape
{
public:
    int x1, y1, x2, y2;
    int counter = 0;
    Choice2() :Shape(6, 240, 0, "选择2") {}
    int df_Rectangle(ExMessage m);
    int df_Circle(ExMessage m);
    void change(ExMessage m,int re_x,int re_y);
    void draw(ExMessage m) override;
};
//清除
class Clear : public Shape
{
public:
    int x, y;
    Clear() :Shape(3,880, 0, "清除") {}
    void draw(ExMessage m) override;
};
//退出
class Quit : public Shape
{
public:
    int x, y;
    Quit() :Shape(4,960, 0, "退出") {}
    void draw(ExMessage m) override;
};
//自由线
class Line : public Shape
{
public:
    int x,y;
    //Line(int x,int y) :x(x),y(y) {}
    Line() :Shape(7,320, 0, "自由线") {}
    void draw(ExMessage m) override;
};
//直线
class Straight_Line : public Shape
{
public:
    int x1, y1, x2, y2;
    Straight_Line() :Shape(8,400, 0, "直线") {}
    void draw(ExMessage m) override;
};
//矩形(有重名函数，加_区别)
class Rectangle_ : public Shape
{
public:
    int x1, y1, x2, y2;
    Rectangle_() :Shape(9,480, 0, "矩形") {}
    void draw(ExMessage m) override;
};
//圆
class Circle : public Shape
{
public:
    int x1,y1,x2,y2,r;
    Circle() :Shape(10,560, 0, "圆") {}
    void draw(ExMessage m) override;
};
//多边形(有重名函数，加_区别)
class Polygon_ :public Shape
{
public:
    int step=0;
    struct point
    {
        int x;
        int y;
    }points[100];
    Polygon_():Shape(11,640,0,"多边形"){}
    void draw(ExMessage m) override;
};

#endif