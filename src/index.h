#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include <string.h>
#include "my_charwork.h"
#include "my_tab.h"

// argc, argv, out, err
typedef int(*command)(int,char**,FILE*, FILE*);

// Recupere la fonction correspondante a la commande id
command i_get(const char *id);
// Applique la fonction (stdout)
int i_call(my_tab args);
// Associe la commande c a la fonction f
void i_add(const char *id, command f);
// Libere l'index entier
void i_free();
// Renvoie le nombre de fonctions dans l'index
int i_count();

#endif
