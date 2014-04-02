#ifndef APPLY_DEF
#define APPLY_DEF

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

/*
 * Execute une commande apres traitement
 */
int apply(my_tab t);

#endif
