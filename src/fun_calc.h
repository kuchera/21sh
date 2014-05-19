#ifndef FUN_CALC_DEF
#define FUN_CALC_DEF

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include "env.h"

/*
 * Calculatrice
 */
int fun_calc(int argc, char **argv);

#endif
