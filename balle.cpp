#include <allegro.h>
#include <iostream>
using namespace std;

#include "point.h"
#include "balle.h"

balle::balle(float abcisse, float ordonnee, float diam) : point(abcisse, ordonnee)
{
    diametre = diam;
}

balle::~balle()
{}


void balle::affiche()
{
    rectfill(page,x,y,x + diametre,y + diametre,makecol(255,0,0));
}


void balle::deplace(/*float dx, float dy*/)
{
    x += deplacementBalleHoriz;
    y += deplacementBalleVert;
}


int balle::collisionRaq(float xraq1, float yraq1, float xraq2)
{
    if ((x >= xraq1) && (x <= xraq2) && (y >= yraq1))
        return 0;

    return 1;
}



void balle::majDplcmtBalle(float x, float y)
{
    deplacementBalleHoriz = x;
    deplacementBalleVert = y;
}
