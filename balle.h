#ifndef __BALLE_H__
#define __BALLE_H__

class balle : public point
{
protected:
    float diametre;
    float deplacementBalleHoriz;
    float deplacementBalleVert;

public:
    balle(float, float, float);
    ~balle();
    void affiche();
    void deplace(/*float, float*/);

    int collisionRaq(float, float, float);
    void majDplcmtBalle(float, float);
};

#endif // __BALLE_H__
