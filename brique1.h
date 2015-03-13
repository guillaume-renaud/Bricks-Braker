#ifndef __BRIQUE1_H__
#define __BRIQUE1_H__

class brique1 : public brique
{
protected:
    BITMAP* my_pic;

public :
    brique1(float, float, float, float/*, int, int*/);  //avec paramètres : x, y, largeur, hauteur
    ~brique1();
    void affiche();

    void majBrique();
};

#endif //__BRIQUE1_H__

