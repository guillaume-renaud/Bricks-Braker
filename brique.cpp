#include <allegro.h>
#include <iostream>
using namespace std;

#include "balle.h"
#include "rectangl.h"
#include "brique.h"


brique::brique(float abs, float ord, float pl , float ph /*, int couleurExterieure, int couleurInterieure*/) : rectangl(abs, ord, pl, ph)
{}

brique::~brique()
{
    //detruire les briques
}


int brique::getCompteur()
{
    return compteur;
}
