#ifndef __BRIQUE2_H__
#define __BRIQUE2_H__

class brique2 : public brique
{

public :
    brique2(float, float, float, float/*, int, int*/);  //avec paramètres : x, y, largeur, hauteur
    ~brique2();
    void affiche();
    void majBrique();
};

#endif //__BRIQUE2_H__

