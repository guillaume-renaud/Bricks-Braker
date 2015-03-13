#include <allegro.h>
#include <iostream>
using namespace std;

#include "liste.h"
#include "listeform.h"
#include "form.h"
#include "point.h"
#include "balle.h"
#include "rectangl.h"
#include "raquette.h"
#include "bouton.h"
#include "menu.h"
#include "listeBrique.h"
#include "brique.h"
#include "brique1.h"
#include "brique2.h"


int main()
{
    int x, y;           // MODIF Variables pour la position de la souris
    int done = 0;		// Pour fin de la boucle
    int indiceBouton=-2;
    float deplacementBalleHoriz = 0.1;
    float deplacementBalleVert = 0.1;

    allegro_init();
    install_keyboard();   // Installe le clavier
    install_mouse();      // Installe la souris

// Sélection d'un driver graphique approprié + initialisation de la résolution de l'écran (640x480)
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,640,480,0,0)!=0)
    {
        allegro_message(allegro_error);
      	allegro_exit();
      	return 1;
    }

// Instanciation des objets graphiques
    //bouton *b = new bouton(500,300,80,50,"Lancer le jeu");
    char *t[]={"iut","info","aspe","dreamteam"};
    menu m(t, 4, 100, 100, 120);
    listeBrique* lb = new listeBrique(250, 100, 400, 30);
    raquette* raq = new raquette(100, 10, 400, 450);
    balle* bal = new balle(350, 350, 10);

// Création du buffer (bitmap intermédiaire)
    form::initPage();

// On met la souris en mode visible
    show_mouse(screen);

// Boucle d'affichage
    while (!done)
    {
        form::affichelisteform();
        form::blitPage();
        form::clearPage();

        // Affectation des positions de la souris
        x = mouse_x;
        y = mouse_y;

        // On récupère l'indice du bouton sur lequel l'user clique(clic gauche)
        if (mouse_b & 1)
            indiceBouton = m.selection(x, y);

        //cout << indiceBouton;

        // Si l'utilisateur appuie "espace", on sort de la boucle et on arrête donc l'affichage
        if (key[KEY_SPACE])
            done = 1;

        if (key[KEY_LEFT])
            raq->deplace(-2);

        if (key[KEY_RIGHT])
            raq->deplace(2);

        if (key[KEY_DOWN])
            bal->majDplcmtBalle(0, 0.5);


        // Si la balle entre en collision avec la raquette
        if (bal->collisionRaq(raq->x1, raq->y1, raq->x2) == 0)
        {
            bal->majDplcmtBalle(0, -0.5);
        }

        bal->deplace();

        if (key[KEY_UP])
            bal->deplace(/*0,-5*/);

        //cout << form::cpt;
    }

    // On repasse en mode texte et on affiche un message annonçant que le programme est terminé
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    allegro_message("Fin du programme");
    exit(EXIT_SUCCESS);

}END_OF_MAIN();
