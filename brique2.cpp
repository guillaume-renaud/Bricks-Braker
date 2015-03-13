#include <allegro.h>
#include <iostream>
using namespace std;

#include "brique.h"
#include "brique2.h"

brique2::brique2(float abs, float ord, float pl , float ph /*, int couleurExterieure, int couleurInterieure*/) : brique(abs,ord,pl,ph/*, int couleurExterieure, int couleurInterieure*/)
{
    couleurbrique = makecol(0,255,0);
}

brique2::~brique2()
{

}

void brique2::affiche()
{
    rectfill(page, x1,y1,x2,y2, couleurbrique);
}
