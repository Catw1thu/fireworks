#include"shape.h"
#include <graphics.h>
#include <easyx.h>

shape::shape()
{

}

void shape::fillcolor()
{
    setfillcolor(color);
    setlinecolor(color);
}

void shape::getcolor(COLORREF cl)
{
    color = cl;
}

shape::~shape()
{

}