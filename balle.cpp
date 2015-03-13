#include <allegro.h>
#include <iostream>
#include <math.h>
using namespace std;

#include "cercle.h"
#include "balle.h"

// Constructeur de balle
balle::balle(float abcisse, float ordonnee, float diam, int pn) : cercle(abcisse, ordonnee, diam)
{
    int i;
    float pas, arg;

    deplacementBalleHoriz = 0;
    deplacementBalleVert = 0;
    diametre = diam;
    tabx = new float[nbPointsBalle = pn];
    taby = new float[nbPointsBalle];

    pas = 360/nbPointsBalle;
    arg = 0;

    for(i = 0; i < nbPointsBalle; i++, arg += pas)
    {
        tabx[i] = x + (diametre/2) * cos(arg * M_PI/180);
        taby[i] = y + (diametre/2) * sin(arg * M_PI/180);

        //cout << taby[2] << "     "  << pas << endl;
    }
}


// Destructeur de balle
balle::~balle()
{}

// Affichage de balle
void balle::affiche()
{
    cercle::affiche();
}

// Fonction de collision entre la balle et la raquette
void balle::collisionRaq(raquette* rak)
{
    float centreRaq, inclinaison;
    float largeurRaq;

    centreRaq = ((rak->x2 + rak->x1) / 2);
    largeurRaq = rak->x2 - rak->x1;


    // Si on touche la raquette
    if ((x >= rak->x1) && (x <= rak->x2) && (y + diametre/2 >= rak->y1))
    {
        // Extrémité gauche
        if (x <= centreRaq - largeurRaq/4)
            inclinaison = 2;
        // Milieu gauche
        else if ((x >= centreRaq - largeurRaq/4) && (x <= centreRaq))
            inclinaison = 1;
        // Extrémité droite
        else if (x >= centreRaq + largeurRaq/4)
            inclinaison = -2;
        // Milieu droit
        else
            inclinaison = -1;

        // Mise à jour des coordonnées pour effectuer le rebond
        majDeplacementBalle(deplacementBalleHoriz-inclinaison, -deplacementBalleVert);
    }
}

// Fonction de déplacement de la balle
void balle::deplace(listeBrique* lb)
{
    int res;

    point::deplace(deplacementBalleHoriz, deplacementBalleVert);
    majDeplacementBalle(deplacementBalleHoriz, deplacementBalleVert);
    res = lb->collisionMur(this);

    if((res == 0) || (res == 4))
        deplacementBalleHoriz = -deplacementBalleHoriz;
    else if((res == 2) || (res == 6))
        deplacementBalleVert = - deplacementBalleVert;
    else if((res == 1) || (res == 3) || (res == 5) || (res == 7))
    {
        deplacementBalleHoriz = deplacementBalleHoriz;
        deplacementBalleVert = -deplacementBalleVert;
    }
}

// Fonction de collision entre la balle et les bords de l'écran
void balle::collisionFenetre(raquette *raq)
{
    // On teste si la balle heurte les limites de la fenêtre
    if (((x + diametre/2) >= page->w) || ((x - diametre/2) <= 0))
        deplacementBalleHoriz = -deplacementBalleHoriz;

    if ((y - diametre/2) <= 0)
        deplacementBalleVert = -deplacementBalleVert;

    if ((taby[2]) >= (raq->y1+raq->getHauteur()))
    {
        allegro_message("Perdu turlututu chapeau pointu");
        x = 350;
        y = 350;
        deplacementBalleHoriz = 0;
        deplacementBalleVert = 0;
    }
}

// Fonction de collision entre la balle et unee brique
int balle::collisionBrique(brique* br)
{
    int i;

    for(i=0; i < nbPointsBalle; i++)
        if((br->collisionBalleRect(tabx[i], taby[i])) == 1)
            return i;

    return -1;
}


// Fonction de mis a jour des coordonnées pour le déplacement de la balle
void balle::majDeplacementBalle (float dx, float dy)
{
    float pas, arg;
    int i;

    deplacementBalleHoriz = dx;
    deplacementBalleVert = dy;

    pas = 360/nbPointsBalle;
    arg = 0;

    for(i = 0; i < nbPointsBalle; i++, arg += pas)
    {
        tabx[i] = x + (diametre/2) * cos(arg * M_PI/180);
        taby[i] = y + (diametre/2) * sin(arg * M_PI/180);
    }
}

