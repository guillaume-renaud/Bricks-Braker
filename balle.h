#ifndef __BALLE_H__
#define __BALLE_H__

#include "brique.h"
#include "cercle.h"
#include "raquette.h"
#include "listebrique.h"

class balle : public cercle
{
protected:
    float deplacementBalleHoriz;
    float deplacementBalleVert;
    float *tabx, *taby;      // Tableaux de coordonnées des points de la balle
    int nbPointsBalle;

public:
    balle(float, float, float, int);
    ~balle();
    void affiche();
    void majDeplacementBalle(float, float);
    void deplace(listeBrique *);

    int collisionBrique(brique*);
    void collisionFenetre(raquette*);
    void collisionRaq(raquette*);
};

#endif // __BALLE_H__
