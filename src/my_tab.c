#include "my_tab.h"

static void my_trealloc(my_tab t)
{
	t->count *= 2;
	t->tab = realloc(t->tab, t->count * sizeof(void*));
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
