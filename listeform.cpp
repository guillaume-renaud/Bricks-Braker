#include <allegro.h>
#include <iostream>
using namespace std;

#include "liste.h"
#include "form.h"
#include "listeform.h"

listeform::listeform() : liste()
{}

listeform::~listeform()
{}

void listeform::affiche()
{
    form *ptr;

    init();

    while(existe())
    {
        ptr = (form*) prochain();
        ptr->affiche();
    }
}
