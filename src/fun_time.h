#ifndef FUN_TIME_DEF
#define FUN_TIME_DEF

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>
#include "constants.h"
#include "index.h"

/*
 * Affiche le temps d'execution de la fonction
 * passee dans les arguments
 */
int fun_time(int argc, char **argv);

#endif
