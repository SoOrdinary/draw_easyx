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
//����
class Save : public Shape
{
public:
    int x, y;
    IMAGE picture;
    Save():Shape(1,0,0,"����") {}
    void draw(ExMessage m) override;
};
//��
class Save_as : public Shape
{
public:
    int x, y;
    IMAGE picture;
    Save_as() :Shape(2,80, 0, "��") {}
    void draw(ExMessage m) override;
};
//ѡ��1
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
    Choice1() :Shape(5,160, 0, "ѡ��1") {}
    void dfs(int x, int y);
    void draw(ExMessage m) override;
};
//ѡ��2
class Choice2 : public Shape
{
public:
    int x1, y1, x2, y2;
    int counter = 0;
    Choice2() :Shape(6, 240, 0, "ѡ��2") {}
    int df_Rectangle(ExMessage m);
    int df_Circle(ExMessage m);
    void change(ExMessage m,int re_x,int re_y);
    void draw(ExMessage m) override;
};
//���
class Clear : public Shape
{
public:
    int x, y;
    Clear() :Shape(3,880, 0, "���") {}
    void draw(ExMessage m) override;
};
//�˳�
class Quit : public Shape
{
public:
    int x, y;
    Quit() :Shape(4,960, 0, "�˳�") {}
    void draw(ExMessage m) override;
};
//������
class Line : public Shape
{
public:
    int x,y;
    //Line(int x,int y) :x(x),y(y) {}
    Line() :Shape(7,320, 0, "������") {}
    void draw(ExMessage m) override;
};
//ֱ��
class Straight_Line : public Shape
{
public:
    int x1, y1, x2, y2;
    Straight_Line() :Shape(8,400, 0, "ֱ��") {}
    void draw(ExMessage m) override;
};
//����(��������������_����)
class Rectangle_ : public Shape
{
public:
    int x1, y1, x2, y2;
    Rectangle_() :Shape(9,480, 0, "����") {}
    void draw(ExMessage m) override;
};
//Բ
class Circle : public Shape
{
public:
    int x1,y1,x2,y2,r;
    Circle() :Shape(10,560, 0, "Բ") {}
    void draw(ExMessage m) override;
};
//�����(��������������_����)
class Polygon_ :public Shape
{
public:
    int step=0;
    struct point
    {
        int x;
        int y;
    }points[100];
    Polygon_():Shape(11,640,0,"�����"){}
    void draw(ExMessage m) override;
};

#endif