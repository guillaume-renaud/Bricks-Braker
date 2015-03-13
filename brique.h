#ifndef __BRIQUE_H__
#define __BRIQUE_H__


class balle;
#include "rectangl.h"


class brique : public rectangl
{
protected :
    int couleurbrique;
    int compteur;
    int afficheImage;

public :
    brique(float, float, float, float);
    virtual ~brique();
    virtual void affiche() = 0;

    virtual void majBrique() = 0;
    void ajoute();
    int getCompteur();
};

#endif //__BRIQUE_H__

