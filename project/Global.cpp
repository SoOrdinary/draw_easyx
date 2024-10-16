#include<graphics.h>
#include"Global.h"
#define MAX_DEF 100

bool project = true;
int _size_ = 5;
int num_rectangle=0,num_circle = 0;
COLORREF _color_ = BLACK;
int way = 0;
int _draw_start_ = WM_LBUTTONDOWN, _draw_next_ = WM_LBUTTONDOWN, _draw_finish_ = WM_LBUTTONDBLCLK;

REC rec[MAX_DEF];
CIR cir[MAX_DEF];