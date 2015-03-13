#include <allegro.h>
#include <iostream>
using namespace std;

#include "liste.h"

void liste::init()
{
    prec = cour = tete;
}


void liste::ajoute(void *val)
{
    ptNoeud aux;
    aux = new tNoeud;
    aux->info = val;
    aux->svt = tete;
    tete = aux;
}


void* liste::prochain()
{
    void *val;

    if(cour != NULL)
    {
        val = cour->info;
        prec = cour;
        cour = cour->svt;

        return val;
    }
    return NULL;
}



void liste::supprime(void *val)
{
    ptNoeud p, prec;

    if(tete != NULL)
    {
        if((tete)->info == val)
        {
            p=(tete)->svt;
            delete(tete);
            tete = p;
        }
        else
        {
            p = tete;

            while((p!=NULL)&&(p->info!= val))
            {
                prec=p;
                p=p->svt;
            }

            if(p != NULL)
            {
                prec->svt = p->svt;
                delete(p);

            }
        }

        //form::cpt--;
    }
}


int liste::existe()
{
    if(cour != NULL)
        return 1;
    return 0;
}
