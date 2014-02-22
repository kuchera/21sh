#ifndef FUN_CD_H
#define FUN_CD_H

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

/*
 * Fonction de deplacement dans les fichiers
 */
int fun_cd(int argc, char **argv, FILE *out, FILE *err);

#endif
