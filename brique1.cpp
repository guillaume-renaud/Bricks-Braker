#include <allegro.h>
#include <iostream>
using namespace std;

#include "brique.h"
#include "brique1.h"

brique1::brique1(float abs, float ord, float pl , float ph /*, int couleurExterieure, int couleurInterieure*/) : brique(abs,ord,pl,ph/*, int couleurExterieure, int couleurInterieure*/)
{
    couleurbrique = makecol(255,0,0);
}

brique1::~brique1()
{}

void brique1::affiche()
{
    rectfill(page, x1,y1,x2,y2, couleurbrique);
}

