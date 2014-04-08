#ifndef APPLY_DEF
#define APPLY_DEF

#include "my_tab.h"
#include "index.h"
#include "redirection.h"

/*
 * Execute une commande apres traitement
 */
int apply(my_tab t);
/*
 * Copie le tableau (mais pas les donnees)
 */
my_tab r_cp(my_tab t);
/*
 * Retourne tous les elements avant sep
 * et les supprime de t
 */
my_tab r_first(my_tab t, const char *sep);


#endif
