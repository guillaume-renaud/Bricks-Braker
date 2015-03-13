#include <allegro.h>
#include <iostream>
using namespace std;

#include "rectangl.h"
#include "bouton.h"

bouton::bouton(float abs, float ord, float pl, float ph, char* pch) : rectangl(abs,ord,pl,ph)
{   int haut,larg;
    chaine = new char [strlen(pch)+1];
    strcpy(chaine, pch);
    haut = text_height(font);
    larg = text_length(font,pch);
    xch = x -larg/2;
    ych = y - haut/2;
}


bouton::bouton(const bouton& s) : rectangl(s)
{

    chaine = new char [strlen(s.chaine)+1];
    strcpy(chaine, s.chaine);
}

bouton::~bouton()
{
    delete(chaine);
}

bouton& bouton::operator=(bouton& s)
{
    rectangl *ad1 = this, *ad2 = &s;
    ad1 = ad2;
    delete(chaine);
    chaine = new char[strlen(s.chaine)+1];
    strcpy(chaine, s.chaine);

    return *this;
}


void bouton::affiche()
{
    rectangl::affiche();
    //rectfill(page,x1,y1,x2,y2,makecol(0,255,0));
    textprintf(page, font, xch, ych, makecol(255,0,0), "%s", chaine);
}
