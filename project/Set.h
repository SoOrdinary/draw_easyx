#ifndef _SET_H_
#define _SET_H_

#include<graphics.h>
#include"Button.h"
#include"Global.h"

class Set
{
public:
    Set(int mode, int x0, int y0, const char* str) :mode(mode), x0(x0), y0(y0), str(str) {}
    ~Set()
    {
        free(menuButton);
        menuButton = nullptr;
    }
public:
    int x0, y0;
    int judg = 0;
    int mode;
    const char* str;
    struct ButtonTool* menuButton = creatButtonTool(x0, y0, 100, 35, str, RGB(236, 244, 255), RGB(204, 213, 240));
    int drawButton(ExMessage m)
    {
        DrawButton(menuButton,20,10);
        if (isInButton(menuButton, m))
            return mode;
        else
            return 0;
    };
    virtual void draw(ExMessage m) = 0;
};
//画笔增大
class draw_size1 :public Set
{
public:
    draw_size1() :Set(1, 0, 765, "画笔增大"){}
    void draw(ExMessage m)override;
};
//画笔减小
class draw_size2 :public Set
{
public:
    draw_size2() :Set(2, 100, 765, "画笔减小") {}
    void draw(ExMessage m)override;
};
//更改颜色
class change_color :public Set
{
public:
    change_color() :Set(3, 200, 765, "更改颜色") {}
    void draw(ExMessage m)override;
};
//开始操作
class draw_start :public Set
{
public:

    draw_start() :Set(4, 300, 765, "开始操作") { judg = 0; }
    void draw(ExMessage m)override;
};
//继续操作
class draw_next :public Set
{
public:
    draw_next() :Set(5, 400, 765, "继续操作") { judg = 0; }
    void draw(ExMessage m)override;
};
//结束操作
class draw_finish :public Set
{
public:
    draw_finish() :Set(6, 500, 765, "结束操作") { judg = 1; }
    void draw(ExMessage m)override;
};
//绘制方式
class paint_way :public Set
{
public:
    paint_way() :Set(7, 600, 765, "绘制方式") { judg = 1; }
    void draw(ExMessage m)override;
};

#endif