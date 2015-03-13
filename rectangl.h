#ifndef __RECTANGL_H__
#define __RECTANGL_H__

#include "point.h"

class rectangl : public point
{
public :
    float l, h, x1, y1, x2, y2;

private :
    void majxy();

public :
    rectangl(float,float,float,float);
    rectangl(const rectangl&);
    ~rectangl();
    rectangl& operator=(rectangl&);

    int collisionBalleRect(float, float);
    void init(float, float,float, float);
    void deplace(float,float);
    void affiche();
};

#endif // __RECTANGL_H__

