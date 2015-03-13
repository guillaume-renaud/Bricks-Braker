#include <allegro.h>
#include <iostream>
using namespace std;

#include "listeform.h"
#include "form.h"

listeform* form::l = new listeform;
int form::cpt = 0;
BITMAP* form::page = NULL;

form::form()
{
    l->ajoute(this);
    //cout << "Constructeur form\n";
    cpt++;
}


form::~form()
{
    l->supprime(this);
    //cout << "Destructeur form\n";
    cpt --;
}


void form::affichelisteform()
{
    l->affiche();
}


void form::initPage()
{
    page = create_bitmap(SCREEN_W,SCREEN_H);

    if (!page)
        allegro_message("Erreur lors de la création du bitmap double buffer");
}


void form::blitPage()
{
    blit(page, screen,0,0,0,0,page->w,page->h);
}


void form::clearPage()
{
    clear_bitmap(page);
}

