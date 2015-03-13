#ifndef __BRIQUE_H__
#define __BRIQUE_H__

#include "rectangl.h"

class brique : public rectangl
{
protected :
    int couleurbrique;
public :
    brique(float, float, float, float);
    virtual ~brique();
    virtual void affiche()=0;
    //virtual int collision()=0;
    void ajoute();
};

#endif //__BRIQUE_H__

