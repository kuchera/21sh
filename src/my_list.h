#ifndef MY_LIST_DEFINE
#define MY_LIST_DEFINE

#include "stdio.h"
#include "stdlib.h"

typedef struct my_list *my_list;
struct my_list
{
	void* elt;
	my_list next;
};

// Renvoie le tableau de pointeurs sur les donnees
void *my_ltoarray(my_list l);
// Renvoie la longueur de la liste
int my_llen(my_list l);
// Ajoute e dans la liste
void my_ladd(my_list* l, void* e);
// Insere e a l'emplacement i (base 0)
void my_linsert(my_list* l, void* e, int i);
// Renvoie l'element a la position i (base 0)
void* my_leltat(my_list l, int i);
// Libere toute la liste
void my_lfree(my_list* l);
// Renvoie le ieme element et le supprime de la liste
void* my_lremoveat(my_list* l, int i);
// Applique f au ieme element de la liste
void my_lapplyto(my_list l, void(*f)(void*), int i);
// Applique f a chaque element de la liste
void my_lapply(my_list l, void(*f)(void*));
// Renvoie l'emplacement du premier element pour lequel f renvoie vrai (-1 si non trouve)
int my_lassert(my_list l, int(*f)(void*));

#endif //MY_LIST_DEFINE
