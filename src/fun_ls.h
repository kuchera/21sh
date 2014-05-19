#ifndef FUN_LS_DEF
#define FUN_LS_DEF

#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <sys/ioctl.h>
#include "env.h"
#include "constants.h"
#include "color.h"
#include "tools.h"

/*
 * Affiche le contenu du repertoire courant
 */
int fun_ls(int argc, char **argv);

/*
 * Retourne le contenu du dossier path
 */
my_tab get_files(char *path);

#endif
