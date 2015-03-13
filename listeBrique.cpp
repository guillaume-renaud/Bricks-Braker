#include <allegro.h>
#include <iostream>
#include <math.h>
using namespace std;

#include "balle.h"
#include "form.h"
#include "liste.h"
#include "listeBrique.h"
#include "brique.h"
#include "brique1.h"
#include "brique2.h"

listeBrique::listeBrique(float abs, float ord, float hMur, float lMur, int nbBriques) : form(), liste()//, r(abs, ord, lMur, hMur)
{
    int i, nbBriquesLigne, decale = 0;
    float largeurBrique;
    float abcisseBrique;
    float aireMurBrique, aireBrique, briquesDerniereLigne;
    int pas = 5;

    brique1 *p1;
    brique2 *p2;

    // Initialisation des attributs
    hauteurMur = hMur;
    largeurMur = lMur;



    aireMurBrique = hauteurMur * largeurMur;
    aireBrique = aireMurBrique / nbBriques;

    largeurBrique = aireBrique / 50;
    nbBriquesLigne = round(largeurMur / (largeurBrique + pas));
    briquesDerniereLigne = nbBriques % nbBriquesLigne;

    abcisseBrique = abs;

    // On boucle nbBriques fois car on crée une brique par tour de boucle
    for (i = 0; i < nbBriques; i++)
    {
        // On passe à la ligne suivante
        if (i % nbBriquesLigne == 0)
        {
            abcisseBrique = abs;
            ord += 25;
        }

        // Les briques pairs sont des brique1 (rouges)
        if (i % 2 == 0)
        {
            if (((briquesDerniereLigne) != 0) && (i >= nbBriques - briquesDerniereLigne) && decale == 0)
            {
                abcisseBrique = abs + ((nbBriquesLigne - briquesDerniereLigne)/2) * (largeurBrique + pas);
                decale = 1;
            }

            p1 = new brique1(abcisseBrique, ord, largeurBrique, 20);
            l->supprime(p1);        // On supprime la brique de la listeform
            ajoute(p1);     // On ajoute la brique à la liste de briques
        }

        // Les briques impairs sont des brique2
        else
        {
            if (((briquesDerniereLigne) != 0) && (i >= nbBriques - briquesDerniereLigne) && decale == 0)
            {
                abcisseBrique = abs + ((nbBriquesLigne - briquesDerniereLigne)/2) * (largeurBrique + pas);
                decale = 1;
            }

            p2 = new brique2(abcisseBrique, ord, largeurBrique, 20);
            l->supprime(p2);
            ajoute(p2);
        }

        abcisseBrique += largeurBrique + pas;     // A chaque ajout d'une brique, la suivante est décalée vers la droite (une largeur de brique +5 de marge)
    }
}

listeBrique::~listeBrique()
{}

void listeBrique::affiche()
{
    brique *ptr;
    init();

    while(existe())
    {
        ptr = (brique*) prochain();
        ptr->affiche();
    }
}



float listeBrique::getLargeurMur()
{
    return largeurMur;
}

float listeBrique::getHauteurMur()
{
    return hauteurMur;
}

int listeBrique::collisionMur(balle* b)
{
    brique* ptr;
    int res;

    init();
    while(existe())
    {
        ptr = (brique*) prochain();
        res = b->collisionBrique(ptr);

        if(res >= 0)
        {
            cout << "\n"<< res;       // Numero point de balle
            ptr->majBrique();

            if (ptr->getCompteur() == 0)
            {
                this->supprime((void*)ptr);
                delete ptr;
            }

            return res;
        }
    }
    return -1;
}
