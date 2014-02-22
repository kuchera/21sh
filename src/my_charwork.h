#ifndef MY_CHARWORK_DEFINE
#define MY_CHARWORK_DEFINE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_tab.h"

// Separe str avec tous les characteres de sep compte le nombre d'elements separes dans size
char** my_split(const char* str, const char* sep, int *size);
// Assemble les size premieres chaines de tab separees par sep
char* my_smerge(char **tab, int size, const char *sep);
my_tab my_tsplit(const char *str, const char *sep);
char* my_tsmerge(my_tab t, const char *sep);
// Alloue et copie str
char* my_stralloc(const char* str);
// Alloue et concatene s1 et s2
char* my_strcat(const char *s1, const char *s2);
// Lis une ligne entree dans la console
char* my_readline();
// Vide le buffer
void my_clrbuf();

#endif //MY_CHARWORK_DEFINE
