#ifndef FUN_CD_H
#define FUN_CD_H

#include <stdio.h>
#include <dirent.h>
#include <string.h>
#ifndef WIN32 
    #include <sys/types.h>
#endif

/*
 * Fonction
 */
int fun_cd(int argc, char **argv);

#endif
