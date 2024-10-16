#ifndef _GLOBAL_H_
#define _GLOBAL_H_

#include<graphics.h>
#define MAX_DEF 100

extern bool project;
extern int _size_;
extern int num_rectangle, num_circle;
extern COLORREF _color_;
extern int way;
extern int _draw_start_, _draw_next_, _draw_finish_;

typedef struct
{
    int x;
    int y;
    int width;
    int high;
}REC;
typedef struct
{
    int x;
    int y;
    int r;
}CIR;
extern REC rec[MAX_DEF];
extern CIR cir[MAX_DEF];

#endif