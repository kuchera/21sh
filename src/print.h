#ifndef PRINT_H
#define PRINT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my_io.h"
#include "index.h"
#include "my_charwork.h"

// Affiche un message de bienvenue
void print_welcome();
// Affiche un message d'aide (liste des fonctions...)
void print_help();
// Affiche l'aide de la fonction id
void print_man(const char *id);
// Affiche la description de la fonction
void print_desc(const char *id);

#endif
