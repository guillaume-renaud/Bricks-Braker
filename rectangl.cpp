#include <allegro.h>
#include <iostream>
using namespace std;

#include "point.h"
#include "rectangl.h"

rectangl::rectangl(float abs, float ord, float pl, float ph) : point(abs, ord)
{
    l = pl;
    h = ph;
    majxy();
}

rectangl::rectangl(const rectangl& s) : point(s)
{
    l = s.l;
    h = s.h;
    x1 = s.x1;
    x2 = s.x2;
    y1 = s.y1;
    y2 = s.y2;
}

rectangl :: ~rectangl(){}

rectangl& rectangl::operator=(rectangl& s)
{
    point *ad1 = this, *ad2 = &s;
    ad1 = ad2;
    l = s.l;
    h = s.h;
    x1 = s.x1;
    x2 = s.x2;
    y1 = s.y1;
    y2 = s.y2;

    return *this;
}


void rectangl::init(float abs, float ord, float pl, float ph)
{
    x = abs;
    y = ord;
    l = pl;
    h = ph;
    majxy();
}


void rectangl::deplace(float dx, float dy)
{
    point::deplace(dx,dy);
    majxy();
}


void rectangl::affiche()
{
    rectfill(page,x1,y1,x2,y2,makecol(0,255,0));
}

void rectangl::majxy()
{
    x1 = x - l/2;
    x2 = x + l/2;
    y1 = y - h/2;
    y2 = y + h/2;
}
