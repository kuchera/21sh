#include "my_list.h"

int my_lassert(my_list l, int(*f)(void*))
{
	int i = 0;
	while (l!=NULL && !(*f)(l->elt))
	{
		l = l->next;
		++i;
	}
	if (l==NULL)
		return -1;
	else
		return i;
}

void *my_ltoarray(my_list l)
{
	if (l == NULL)
		return NULL;
	void **tab = malloc(my_llen(l) * sizeof(void*));
	int i = 0;
	while (l != NULL)
	{
		tab[i] = l->elt;
		l = l->next;
		++i;
	}
	return tab;
}

int my_llen(my_list l)
{
	int i=0;
	while (l != NULL)
	{
		l = l->next;
		i++;
	}
	return i;
}

void my_ladd(my_list* l, void* e)
{
	if (*l == NULL)
	{
		*l = malloc(sizeof(struct my_list));
		(**l).elt = e;
		(**l).next = NULL;
	}
	else
	{
		while ((**l).next != NULL)
			l = &((**l).next);
		(**l).next = malloc(sizeof(struct my_list));
		(**l).next->elt = e;
		(**l).next->next = NULL;
	}
}

void my_linsert(my_list* l, void* e, int i)
{
	while (i > 0)
	{
		l = &((**l).next);
		i--;
	}
	my_list n = malloc(sizeof(struct my_list));
	n->elt = e;
	n->next = *l;
	*l = n;
}

void my_lfree(my_list* l)
{
	my_list p;
	while (*l != NULL)
	{
		p = *l;
		*l = (**l).next;
		free(p);
	}
}

void* my_leltat(my_list l, int i)
{
	while (i > 0)
	{
		l = l->next;
		i--;
	}
	return l->elt;
}

void *my_lremoveat(my_list* l, int i)
{
	my_list p;
	void *r;
	while (i > 0)
	{
		l = &((**l).next);
		i--;
	}
	p = *l;
	*l = (**l).next;
	r = p->elt;
	free(p);
	return r;
}

void my_lapplyto(my_list l, void(*f)(void*), int i)
{
	(*f)(my_leltat(l, i));
}

void my_lapply(my_list l, void(*f)(void*))
{
	while (l != NULL)
	{
		(*f)(l->elt);
		l = l->next;
	}
}
