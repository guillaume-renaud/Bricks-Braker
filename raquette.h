#ifndef __RAQUETTE_H__
#define __RAQUETTE_H__

#include "rectangl.h"

class raquette : public rectangl
{
protected:
    int largeurRaquette;
    int hauteurRaquette;

public:
    raquette(float, float, float, float);
    ~raquette();

    void deplace(float);
    int getHauteur();

};

#endif //__RAQUETTE_H__
