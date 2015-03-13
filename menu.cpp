#include <allegro.h>
#include <iostream>
using namespace std;


#include "menu.h"

menu::menu(char **t, int pnb, float pXali, float pYali, float ppas) : form()
{
    int i;
    float ya;

    nb = pnb;
    pas = ppas;
    Yali = pYali;
    Xali = pXali;

    tab = new bouton*[nb];

    ya = Yali;
    for(i=0;i<nb;i++)
    {
        tab[i] = new bouton(Xali, ya, 0.8*Xali*2, 0.6*pas, t[i]);
        l->supprime(tab[i]);        // On supprime le bouton de la listeform "l" ici psk ca veut dire que c'est un bouton de menu
        ya+= pas;
    }
}


//Constructeur par recopie
menu::menu(const menu &s) : form()
{
    int i;

    nb = s.nb;
    pas = s.pas;
    Yali = s.Yali;
    Xali = s.Xali;


    tab = new bouton*[nb];
    for(i=0;i<nb;i++)
        tab[i] = new bouton(*(s.tab[i]));       // Invocation du constructeur par recopie de bouton
}


menu::~menu()
{
    int i;
    for(i=0; i<nb; i++)
        delete (tab[i]);

    delete (tab);

//effacement graphique
}


menu& menu::operator=(menu &s)
{
    int i;

    if(this != &s)
    {
        for(i=0; i<nb; i++)
            delete tab[i];
        delete tab;

        nb = s.nb;
        pas = s.pas;
        Yali = s.Yali;
        Xali = s.Xali;

        tab = new bouton*[nb];
        for(i=0;i<nb;i++)
            tab[i] = new bouton(*(s.tab[i]));
    }
    return *this;
}


void menu::affiche()
{
    int i;

    for(i=0;i<nb;i++)
        tab[i]->affiche();          // Invocation de la fonction affiche de bouton
}



int menu::selection(int abs, int ord)
{
    int i;

    for(i = 0;i < nb;i++)
        if ((tab[i]->x1 < abs) && (tab[i]->x2 > abs) && (tab[i]->y1 < ord) && (tab[i]->y2 > ord))
            return i;

    return -1;

}
