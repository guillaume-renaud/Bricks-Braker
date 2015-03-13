#include <allegro.h>
#include <iostream>
using namespace std;

#include "form.h"
#include "point.h"

point::point(float abs,float ord): form()
{
    x = abs;
    y = ord;
}

point::point(const point& s): form()
{
    x = s.x;
    y = s.y;
}

point::~point(){}

point& point::operator=(const point& s)
{
    x = s.x;
    y = s.y;

    return *this;                 // this est un addresse donc on renvoit l'objet pour prendre sa référence par la suite
}

void point::init(float abs, float ord)
{
    x = abs;
    y = ord;
}


void point::deplace(float dx, float dy)
{
    x += dx;
    y += dy;
}


/*void point::affiche()
{
    cout << "x=" << x << "  y=" << y << endl;
}*/


