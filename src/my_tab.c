#include "my_tab.h"

static void f(void *e)
{
	puts(e);
}

void my_tprint(my_tab t)
{
	my_tapply(t, &f);
}

void my_tflush(my_tab t)
{
	t->count = 0;
}

my_tab my_tbuild(void **tab, int size)
{
	my_tab t = my_tnew();
	t->size = size;
	t->count = size;
	t->tab = tab;
	return t;
}

static void my_trealloc(my_tab t)
{
	t->size *= 2;
	t->tab = realloc(t->tab, t->size * sizeof(void*));
}

void my_taddtab(my_tab t, void **tab, int count)
{
	int i = 0;
	while (i < count)
	{
		my_tadd(t, tab[i]);
		++i;
	}
}

void my_tapply(my_tab t, void(*f)(void*))
{
	int i;
	for (i=0 ; i<t->count ; ++i)
		(*f)(t->tab[i]);
}

void my_tapplyto(my_tab t, void(*f)(void*), int i)
{
	(*f)(t->tab[i]);
}

int my_tassert(my_tab t, int(*f)(void*))
{
	int i = 0;
	while (i < t->count && !(*f)(t->tab[i]))
		++i;
	if (i < t->count)
		return i;
	return -1;
}

int my_tlen(my_tab t)
{
	return t->count;
}

void* my_trmat(my_tab t, int i)
{
	void *ret = t->tab[i];
	t->count -= 1;
	while (i < t->count)
	{
		t->tab[i] = t->tab[i+1];
		++i;
	}
	return ret;
}

void* my_tget(my_tab t, int i)
{
	return t->tab[i];
}

void* my_tpop(my_tab t)
{
	t->count -= 1;
	return t->tab[t->count];
}

void my_tadd(my_tab t, void *e)
{
	if (t == NULL)
		t = my_tnew();
	else if (t->count == t->size)
		my_trealloc(t);
	t->tab[t->count] = e;
	t->count += 1;
}

my_tab my_tnew()
{
        my_tab t = malloc(sizeof(struct my_tab));
        t->size = MY_TAB_INITIAL_SIZE;
        t->count = 0;
        t->tab = malloc(t->size * sizeof(void*));
        return t;
}

void my_tfree(my_tab t)
{
	free(t->tab);
	free(t);
}

void* my_tlast(my_tab t)
{
	return my_tget(t, t->count - 1);
}

void my_tffree(my_tab t, void(*f)(void*))
{
	my_tapply(t, f);
	my_tfree(t);
}
