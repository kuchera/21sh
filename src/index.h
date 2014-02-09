#ifndef INDEX_H
#define INDEX_H

#include "command.h"
#include "my_list.h"

// Recupere la fonction correspondante a la commande id
int (*i_get(int,char**))(char *id);
// Associe la commande c a la fonction f
void i_add(command c, int (*f)(int, char**));
// Libere l'index entier
void i_free();
// Renvoie le nombre de fonctions dans l'index
int i_count();

#endif
