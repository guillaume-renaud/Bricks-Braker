#ifndef __MENU_H__
#define __MENU_H__

#include "bouton.h"

class menu : public form         // class utilisant la composition
{
protected :
    bouton **tab;           // Stockage des adresses des boutons dans un tableau
    int nb;          // Nombre de boutons du tableau
    float Xali, Yali, pas;  // Marge en X, en Y et le pas entre chaque bouton*

public :
    menu(char **t, int, float, float, float);
    menu(const menu&);
    ~menu();
    menu& operator=(menu&);

    void init(float, float, float);
    void affiche();

    // A faire fonction selection
    int selection(int, int);      //on retourne le numéro du bouton sélectionné
};

#endif //__MENU_H__
