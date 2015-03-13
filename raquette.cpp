#include <allegro.h>
#include <iostream>
using namespace std;

#include "rectangl.h"
#include "raquette.h"

raquette::raquette(float larg, float haut, float abcisse, float ordonnee) : rectangl(abcisse, ordonnee, larg, haut)
{
    largeurRaquette = larg;
    hauteurRaquette = haut;
}

raquette::~raquette()
{}

void raquette::deplace(float abcisse)
{
    rectangl::deplace(abcisse,0);
}


int raquette::getHauteur()
{
    return hauteurRaquette;
}
