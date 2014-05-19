#ifndef FUN_VP_DEF
#define FUN_VP_DEF

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "my_charwork.h"
#include "env.h"

/*
 * Execute la commande dans le terminal de l'os
 */
int fun_vp(int argc, char **argv);

#endif
