#ifndef _SHAPE2_H_
#define _SHAPE2_H_

#include<graphics.h>
#include"Button.h"
#include"Global.h"
class Shape_other
{
public:
    bool isDown = false;
    int x0, y0;
    int judg = 1;
    IMAGE picture;
    virtual void draw(ExMessage m) = 0;
};
//直线
class Straight_Line2 : public Shape_other
{
public:
    int x1, y1, x2, y2;
    void draw(ExMessage m) override;
};
//矩形(有重名函数，加_区别)
class Rectangle_2 : public Shape_other
{
public:
    int x1, y1, x2, y2;
    void draw(ExMessage m) override;
};
//圆
class Circle2 : public Shape_other
{
public:
    int x1, y1, x2, y2, r;
    void draw(ExMessage m) override;
};
//多边形(有重名函数，加_区别)
class Polygon_2 :public Shape_other
{
public:
    int step = 0;
    struct point
    {
        int x;
        int y;
    }points[100];
    void draw(ExMessage m) override;
};

#endif

