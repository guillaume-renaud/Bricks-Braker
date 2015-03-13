#include <allegro.h>
#include <iostream>
using namespace std;

#include "form.h"
#include "liste.h"
#include "listeBrique.h"
#include "brique.h"
#include "brique1.h"
#include "brique2.h"

listeBrique::listeBrique(float abs, float ord, float largeurMur, int nbBriques) : form(),liste()
{
    int i;
    float largeurBrique;
    float hauteurMur;
    float abcisseBrique;

    // a faire passer en paramètre
    brique1 *p1;
    brique2 *p2;

    largeurBrique = (largeurMur / 10) - 5;      // la largeur d'une brique est la taille du mur divisé par le nombre de briques par ligne, -5 de marge
    abcisseBrique = abs;

    // On boucle nbBriques fois car on crée une brique par tour de boucle
    for (i = 0; i < nbBriques; i++)
    {
        // Si on est à 10 briques ajoutées, on passe à la ligne suivante (10 briques par ligne)
        if (i % 10 == 0)
        {
            abcisseBrique = abs;
            ord += 25;
        }

        // Les briques pairs sont des brique1
        if (i % 2 == 0)
        {
            p1 = new brique1(abcisseBrique, ord, largeurBrique, 20);

            l->supprime(p1);        // On supprime la brique de la listeform

            ajoute(p1);     // On ajoute la brique à la liste de briques
        }

        // Les briques impairs sont des brique2
        else
        {
            p2 = new brique2(abcisseBrique, ord, largeurBrique, 20);

            l->supprime(p2);

            ajoute(p2);
        }


        abcisseBrique += largeurBrique + 5;     // A chaque ajout d'une brique, la suivante est décalée vers la droite (une largeur de brique +5 de marge)
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
        cout << endl;
    }
}
