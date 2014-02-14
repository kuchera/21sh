#ifndef MY_CHARWORK_DEFINE
#define MY_CHARWORK_DEFINE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "my_list.h"

// Separe str avec tous les characteres de sep compte le nombre d'elements separes dans size
char** my_split(const char* str, const char* sep, int *size);
// Alloue et copie str
char* my_stralloc(const char* str);
// Lis une ligne entree dans la console
char* my_readline();
// Vide le buffer
void my_clrbuf();

#endif //MY_CHARWORK_DEFINE
