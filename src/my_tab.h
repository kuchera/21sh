#ifndef MY_TAB_DEFINE
#define MY_TAB_DEFINE

#include <stdlib.h>
#include <stdio.h>

typedef struct my_tab *my_tab;
struct my_tab
{
	int size;
	int count;
	void **tab;
};

#define MY_TAB_INITIAL_SIZE 10

// Cree un tableau vide
my_tab my_tnew();
// Construit un nouveau tableau avec tab
my_tab my_tbuild(void **tab, int size);
// Libere le tableau (elements a liberer)
void my_tfree(my_tab t);
// Renvoie la longueur du tableau
int my_tlen(my_tab t);
// Ajoute e
void my_tadd(my_tab t, void *e);
// Ajoute count elements de tab
void my_taddtab(my_tab t, void **tab, int count);
// Retourne et supprime le dernier element
void* my_tpop(my_tab t);
// Retourne l'element a la position i
void* my_tget(my_tab t, int i);
// Supprime l'element a l'emplacement i
void* my_trmat(my_tab t, int i);
// Applique f a tous les elements
void my_tapply(my_tab t, void(*f)(void*));
// Applique f a l'element i
void my_tapplyto(my_tab t, void(*f)(void*), int i);
// Renvoie l'index du premier element qui verifie f
int my_tassert(my_tab t, int(*f)(void*));
// Affiche chaque element (char*)
void my_tprint(my_tab t);

#endif
