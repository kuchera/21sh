#ifndef FUN_DISPLAY_DEF
#define FUN_DISPLAY_DEF

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "env.h"

/*
 * Affichage d'images
 */
int fun_display(int argc, char **argv);

#endif
