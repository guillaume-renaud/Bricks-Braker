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

#define LARGEUR_PAGE 640

int main()
{
    int x, y;           // MODIF Variables pour la position de la souris
    int done = 0;		// Pour fin de la boucle
    int indiceBouton=-2;
    float deplacementBalleHoriz;
    float deplacementBalleVert;
    float vitesseRaq = 5;
    bool pause = false;

    // Nombre de couleurs gérées par le programme
    set_color_depth(32);

    allegro_init();
    install_keyboard();   // Installe le clavier
    install_mouse();      // Installe la souris

    // Sélection d'un driver graphique approprié + initialisation de la résolution de l'écran (640x480)
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,LARGEUR_PAGE,480,0,0)!=0)
    {
        allegro_message(allegro_error);
      	allegro_exit();
      	return 1;
    }

    // Instanciation des objets graphiques
    //bouton *b = new bouton(500,300,80,50,"Lancer le jeu");
    char *t[]={"iut","info","aspe","dreamteam"};
    //menu m(t, 4, 70, 50, 60);
    listeBrique* lb = new listeBrique(190, 20, 400, 400, 25);
    raquette* raq = new raquette(100, 10, 400, 450);
    balle* bal = new balle(350, 350, 10,8);

    // Création du buffer (bitmap intermédiaire)
    form::initPage();

    // On met la souris en mode visible
    show_mouse(screen);

    // Boucle d'affichage
    while (!done)
    {
        form::affichelisteform();
        vsync();        // gère les images par seconde du ton jeu par rapport au rafraîchissement de l'écran
        form::blitPage();
        form::clearPage();

        // Affectation des positions de la souris
        x = mouse_x;
        y = mouse_y;

        // On récupère l'indice du bouton sur lequel l'user clique(clic gauche)
        //if (mouse_b & 1)
            //indiceBouton = m.selection(x, y);

        //cout << indiceBouton;

        if (key[KEY_ESC])
            while(pause == false)
            {
                if(key[KEY_P])
                    pause = true;
            }
        pause = false;

        // Si l'utilisateur appuie "espace", on sort de la boucle et on arrête donc l'affichage
        if (key[KEY_SPACE])
            done = 1;

        if ((key[KEY_LEFT]) && (raq->x1 > 0))
            raq->deplace(-vitesseRaq);

        if ((key[KEY_RIGHT]) && (raq->x2 < LARGEUR_PAGE))
            raq->deplace(vitesseRaq);

        if (key[KEY_DOWN])
        {
            bal->majDeplacementBalle(0, 3);
        }

        // Si la balle entre en collision avec la raquette
        bal->collisionRaq(raq);

        // Si elle entre en collision avec les bords de l'écran
        bal->collisionFenetre(raq);

        // Déplacement de la balle + Gère collision brique
        bal->deplace(lb);


        // Accélération vitesse balle
        if (key[KEY_UP])
            bal->deplace(lb);

        //cout << form::cpt;
    }

    // On repasse en mode texte et on affiche un message annonçant que le programme est terminé
    set_gfx_mode(GFX_TEXT,0,0,0,0);
    allegro_message("Fin du programme");
    exit(EXIT_SUCCESS);

}END_OF_MAIN();
