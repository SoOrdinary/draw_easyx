#include<iostream>
#include<math.h>
#include<string.h>
#include"Set.h"
using namespace std;
int operate[] = { WM_LBUTTONDOWN ,WM_LBUTTONDBLCLK ,WM_MBUTTONDOWN ,WM_MBUTTONDBLCLK ,WM_RBUTTONDOWN ,WM_RBUTTONDBLCLK };
int color[] = { BLACK,RED,GREEN,BLUE };
//��������
void draw_size1::draw(ExMessage m)
{
    if (_size_ < 9 && m.x != x0 && m.message == WM_LBUTTONDOWN)
    {
        x0 = m.x;
        _size_++;
    }
    setlinestyle(_size_);
}
//���ʼ�С
void draw_size2::draw(ExMessage m)
{
    if (_size_ >1 && m.x != x0 && m.message == WM_LBUTTONDOWN)
    {
        x0 = m.x;
        _size_--;
    }
    setlinestyle(_size_);
}
//������ɫ
void change_color::draw(ExMessage m)
{
    if (m.x != x0 && m.message == WM_LBUTTONDOWN)
    {
        x0 = m.x;
        judg++;
        judg %= sizeof(color) / sizeof(color[0]);
        _color_ = color[judg];
    }
    if (m.x != x0 && m.message == WM_RBUTTONDOWN)
    {
        x0 = m.x;
        (judg--);
        judg += sizeof(operate);
        judg %= sizeof(color) / sizeof(color[0]);
        _color_ = color[judg];
    }
}
//��ʼ����
void draw_start::draw(ExMessage m)
{
    if (m.x != x0 && m.message == WM_LBUTTONDOWN)
    {
        x0 = m.x;
        judg++;
        judg %= sizeof(operate)/sizeof(operate[0]);
        _draw_start_ = operate[judg];
    }
    if (m.x != x0 && m.message == WM_RBUTTONDOWN)
    {
        x0 = m.x;
        judg += (sizeof(operate) - 1);
        judg %= sizeof(operate) / sizeof(operate[0]);
        _draw_start_ = operate[judg];
    }
}
//��������
void draw_next::draw(ExMessage m)
{
    if (m.x != x0 && m.message == WM_LBUTTONDOWN)
    {
        x0 = m.x;
        judg++;
        judg %= sizeof(operate) / sizeof(operate[0]);
        _draw_next_ = operate[judg];
    }
    if (m.x != x0 && m.message == WM_RBUTTONDOWN)
    {
        x0 = m.x;
        judg += (sizeof(operate)-1);
        judg %= sizeof(operate) / sizeof(operate[0]);
        _draw_next_ = operate[judg];
    }
}
//��������
void draw_finish::draw(ExMessage m)
{
    if (m.x != x0 && m.message == WM_LBUTTONDOWN)
    {
        x0 = m.x;
        judg++;
        judg %= sizeof(operate) / sizeof(operate[0]);
        _draw_finish_ = operate[judg];
    }
    if (m.x != x0 && m.message == WM_RBUTTONDOWN)
    {
        x0 = m.x;
        judg += (sizeof(operate) - 1);
        judg %= sizeof(operate) / sizeof(operate[0]);
        _draw_finish_ = operate[judg];
    }
}
//���Ʒ�ʽ
void paint_way::draw(ExMessage m)
{
    if (m.x != x0 && m.message == WM_LBUTTONDOWN)
    {
        x0 = m.x;
        way++;
        way %= 2;
    }
    if (m.x != x0 && m.message == WM_RBUTTONDOWN)
    {
        x0 = m.x;
        way += (2-1);
        way %= 2;
    }
}