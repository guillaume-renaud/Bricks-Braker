#ifndef __RAQUETTE_H__
#define __RAQUETTE_H__


class raquette : public rectangl
{
private:
    int largeurRaquette;
    int hauteurRaquette;

public:
    raquette(float, float, float, float);
    ~raquette();

    void deplace(float);

    void collision();
};

#endif //__RAQUETTE_H__
