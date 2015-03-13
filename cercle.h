#ifndef __CERCLE_H__
#define __CERCLE_H__

#include "point.h"

class cercle : public point
{
protected:
    float diametre;

public:
    cercle(float, float, float);
    virtual ~cercle();
    virtual void affiche() = 0;

};

#endif // __CERCLE_H__
