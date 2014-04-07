#ifndef REDIRECTION_DEF
#define REDIRECTION_DEF

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "my_tab.h"
#include "index.h"
#include "env.h"
#include "apply.h"
#include <err.h>

/*
 * Applique la redirection, retourne le dernier code d'erreur
 */
int redirect(my_tab t);
// Retourne l'element suivant de sep et les supprime de t 
char* a_getff(my_tab t, const char *sep);
// Retourne le fd de input (<)
int a_getinf(my_tab t);
// Remplit out et err avec toutes les sorties
void a_getout(my_tab t, my_tab out, my_tab err);
void a_getoutf(my_tab t, my_tab out, my_tab out2, const char *s, int append);
void a_free(void *e);

#endif
