#ifndef __FORM_H__
#define __FORM_H__

#include <allegro.h>
#include "listeform.h"

class form
{
protected:
    static listeform *l;
    static BITMAP *page;

public :
    static int cpt;         // a changer!!!!
    form();
    virtual ~form();
    virtual void affiche()=0;
    static void affichelisteform();
    static void initPage();
    static void clearPage();
    static void blitPage();
};

#endif // __FORM_H__

