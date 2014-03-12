#ifndef INDEX_H
#define INDEX_H

#include <stdio.h>
#include <string.h>
#include "my_charwork.h"
#include "constants.h"
#include "my_tab.h"

// Prototype de la fonction de base. Toutes les fonctions deveront respecter ce prototype.
// Arguments : argc, argv, out, errout
typedef int(*command)(int,char**,FILE*, FILE*);

// Recupere la fonction correspondante a la commande id
command i_get(const char *id);
// Cherche la fonction correspondant au premier argument (retourne -1 si elle n'est pas dans l'index et l'applique aux autres arguments. Retourne le retour de la fonction appliquee.
int i_call(my_tab args);
// Associe la commande c a la fonction f
void i_add(const char *id, command f);
// Libere l'index
void i_free();
// Renvoie le nombre de fonctions dans l'index
int i_count();
// Renvoie l'id de la commande a la position i
char* i_getat(int i);
// Initialise l'index
void i_init();

#endif
