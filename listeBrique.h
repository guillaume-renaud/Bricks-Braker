#ifndef __LISTEBRIQUE_H__
#define __LISTEBRIQUE_H__

class listeBrique : public form, public liste
{
public :
    listeBrique(float, float, float, int);
    ~listeBrique();

    void affiche();
};

#endif //__LISTEBRIQUE_H__
