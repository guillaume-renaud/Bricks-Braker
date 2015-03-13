#ifndef __LISTEBRIQUE_H__
#define __LISTEBRIQUE_H__


class balle;

class listeBrique : public form, public liste
{
protected:
    float largeurMur, hauteurMur;

public :
    listeBrique(float, float, float, float, int);
    ~listeBrique();

    int collisionMur(balle *);
    float getLargeurMur();
    float getHauteurMur();
    void affiche();
};

#endif //__LISTEBRIQUE_H__
