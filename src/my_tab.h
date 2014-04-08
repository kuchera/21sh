#ifndef MY_TAB_DEFINE
#define MY_TAB_DEFINE

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
// Construit un nouveau tableau a partir des size premiers elements de tab
my_tab my_tbuild(void **tab, int size);
// Libere le tableau (elements a liberer prealablement)
void my_tfree(my_tab t);
// Comme my_tfree mais applique f a tous les elements avant de liberer
void my_tffree(my_tab t, void(*f)(void*));
// Renvoie le nb d'elements dans t
int my_tlen(my_tab t);
// Ajoute e dans t
void my_tadd(my_tab t, void *e);
// Ajoute count elements de tab dans t
void my_taddtab(my_tab t, void **tab, int count);
// Retourne et supprime le dernier element de t
void* my_tpop(my_tab t);
// Retourne l'element a la position i
void* my_tget(my_tab t, int i);
// Insere e a la position i
void my_tinsert(my_tab t, void *e, int i);
// Retourne le dernier element de t
void* my_tlast(my_tab t);
// Supprime l'element a l'emplacement i
void* my_trmat(my_tab t, int i);
// Supprime tous les elements du tableau
void my_tflush(my_tab t);
// Applique f a tous les elements
void my_tapply(my_tab t, void(*f)(void*));
// Applique f a l'element i
void my_tapplyto(my_tab t, void(*f)(void*), int i);
// Renvoie l'index du premier element qui verifie f
int my_tassert(my_tab t, int(*f)(void*));
// Affiche chaque element de t (doivent etre des char*)
void my_tprint(my_tab t);
//Trie les elements de t(doivent etre des char*)
void my_tsort(my_tab t);

#endif
