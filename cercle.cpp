#include <allegro.h>
#include <iostream>
using namespace std;

#include "point.h"
#include "cercle.h"

cercle::cercle(float abcisse, float ordonnee, float diam) : point(abcisse, ordonnee)
{
    diametre = diam;
}

cercle::~cercle()
{}



void cercle::affiche()
{
    circlefill(page, x, y, diametre/2, makecol(100,100,255));
}

