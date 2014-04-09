#ifndef FUN_MKDIR_DEF
#define FUN_MKDIR_DEF

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include "my_charwork.h"
#include "tools.h"
#include "env.h"

int fun_mkdir(int argc, char **argv);

#endif
