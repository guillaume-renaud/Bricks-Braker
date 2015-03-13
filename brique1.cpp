#include <allegro.h>
#include <iostream>
using namespace std;

#include "brique.h"
#include "brique1.h"




brique1::brique1(float abs, float ord, float pl , float ph /*, int couleurExterieure, int couleurInterieure*/) : brique(abs,ord,pl,ph/*, int couleurExterieure, int couleurInterieure*/)
{
    my_pic = new BITMAP;

    compteur = 3;
    couleurbrique = makecol(255,0,0);
    afficheImage = 1;

    my_pic = load_bitmap("oeuf.bmp", NULL);
}

brique1::~brique1()
{}

void brique1::affiche()
{
    rectfill(page, x1,y1,x2,y2, couleurbrique);

    if(afficheImage == 1)
        stretch_blit(my_pic, page, 5, 5, 100, 100, x1, y1, x2-x1+1, y2-y1+1);
}


void brique1::majBrique()
{
    compteur--;

    switch(compteur)
    {
        case 1:
        {
            destroy_bitmap(my_pic);
            afficheImage = 0;
            my_pic = load_bitmap("nugget.bmp", NULL);
            afficheImage = 1;
            break;
        }

        case 2:
        {
            destroy_bitmap(my_pic);
            afficheImage = 0;
            my_pic = load_bitmap("tux.bmp", NULL);
            afficheImage = 1;
            break;
        }
    }
}
