#ifndef MY_IO_DEFINE
#define MY_IO_DEFINE

#include <stdlib.h>
#include <stdio.h>

#include "my_list.h"
#include "string.h"

// Ecrit str dans file
int my_fwrite(const char *file, const char *str);
// Ajoute str a la fin de file
int my_fadd(const char *file, const char* str);
// Met dans out le contenu du fichier
int my_fread(const char *file, char **out);
// Renvoie la longueur du fichier (bytes)
long my_flen(const char *file);
// Renvoie la longueur du fichier
long my_fflen(FILE *file);
// Lis la premiere ligne du fichier et la retourne
char* my_freadline(FILE *f);

#endif //MY_IO_DEFINE
