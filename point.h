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

    void deplace(float, float);

    void init(float, float);
};

#endif // __POINT_H__
