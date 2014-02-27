#ifndef ENV_DEFINE
#define ENV_DEFINE

#include <stdlib.h>
#include "my_charwork.h"
#include "my_tab.h"

#define PATH_SEPARATORS	"/"

// Retourne le repertoire courant (ne pas modifier)
char* home();
// Retourne le tableau construit a partir de path
my_tab build_path(const char *path);
// Transforme le chemin en chaine de caracteres
char* pathtos(my_tab t);
// Definit le path ou le retourne si s est NULL
my_tab path(my_tab path);
// Ajoute le dossier dir au path
void path_add(const char *dir);
// Remonte dans le repertoire parent
void path_up();
// Definit ou retourne le PS1
char* prompts(char *s);

#endif
