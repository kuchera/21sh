#ifndef FUN_CAT_H
#define FUN_CAT_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include "my_charwork.h"
#include "env.h"

/*
 * Fonction de lecture de fichiers
 * cat FILENAME affiche le contenu
 * du fichier FILENAME dans la
 * console
 */
int fun_cat(int argc, char **argv, FILE *out, FILE *err);

#endif
