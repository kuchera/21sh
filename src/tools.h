#ifndef TOOLS_DEF
#define TOOLS_DEF

#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_charwork.h"

/*
 * Retourne 1 si le parametre eest present, 0 sinon
 */
int has_param(int argc, char **argv, char p);
/*
 * Teste si path/file est un dossier
 */
int is_dir(char *path, char *file);
/*
 * Teste si file est un dossier
 */
int is_directory(char *file);
/*
 * Teste si le fichier est executable
 */
int is_exec(char *path, char *file);

#endif
