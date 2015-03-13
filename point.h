#ifndef __POINT_H__
#define __POINT_H__

#include "form.h"

class point : public form
{
protected :
    float x,y;

public :
    point(float,float);
    point(const point&);
    ~point();
    point& operator=(const point&);

    void init(float, float);
    void deplace(float,float);
};

#endif // __POINT_H__
