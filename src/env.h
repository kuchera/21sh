#ifndef ENV_DEFINE
#define ENV_DEFINE

#include <stdlib.h>
#include <unistd.h>
#include "my_charwork.h"
#include "my_tab.h"
#include "color.h"

#define PATH_SEPARATORS	"/"

// Retourne le repertoire d'appel
char* call_dir();
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
// Retourne le nb de dossiers dans path
int path_len();
// Va a la racine
void path_root();
// Va au home
void path_home();
// Retourne le path sous forme de string
char* path_string();
// Definit ou retourne le PS1
char* prompts();

#endif
