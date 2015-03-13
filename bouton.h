#ifndef __BOUTON_H__
#define __BOUTON_H__

#include "rectangl.h"

class bouton : public rectangl
{
protected :
    char* chaine;
    int xch,ych;

public :
    bouton(float, float, float, float, char*);
    bouton(const bouton&);
    ~bouton();
    bouton& operator=(bouton&);

    void init(float, float, float, float, char*);
    void affiche();
};

#endif //__BOUTON_H__
