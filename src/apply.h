#ifndef APPLY_DEF
#define APPLY_DEF

#include <stdio.h>
#include <stdlib.h>
#include "my_tab.h"
#include "index.h"

/*
 * Execute une commande apres traitement
 */
int apply(my_tab t);
/*
 * Supprime du tableau et retourne un autre tableau avec 
 * tous les elements jusqu'a sep (exclu)
 */
my_tab a_first(my_tab t, const char *sep);

#endif
