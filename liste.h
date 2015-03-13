#ifndef __LISTE_H__
#define __LISTE_H__

typedef struct noeud
{
    void* info;
    struct noeud* svt;
}tNoeud, *ptNoeud;

class liste
{
    ptNoeud tete;
    ptNoeud cour;
    ptNoeud prec;
public :
    void init();
    void ajoute(void*);
    void* prochain();
    void supprime(void*);
    int existe();
};

#endif // __LISTE_H__
