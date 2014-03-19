#include "index.h"

// STATIC DECLARATIONS

struct el
{
	char *id;
	command f;
};

static void i_free_el(void *e)
{
	struct el *elt = e;
	free(elt->id);
	free(elt);
}

static my_tab mindex(my_tab t)
{
	static my_tab tab = NULL;
	if (t)
		tab = t;
	else if (!tab)
		tab = my_tnew();
	return tab;
}

// FUNCTIONS

int i_call(my_tab args)
{
	command f = i_get(my_tget(args, 0));
	if (!f)
		return NOSUCHFUNCTION21;
	return f(args->count, (char**)(args->tab));
}

command i_get(const char *id)
{
	my_tab t = mindex(NULL);
	command f = NULL;
	struct el *e;
	int i = 0, c = i_count();
	while (i < c)
	{
		e = my_tget(t, i);
		if (!strcmp(id, e->id))
		{
			i = c;
			f = e->f;
		}
		++i;
	}
	return f;
}

void i_add(const char *id, command f)
{
	struct el *e = malloc(sizeof(struct el));
	e->id = my_stralloc(id);
	e->f = f;
	my_tab t = mindex(NULL);
	my_tadd(t, e);
	mindex(t);
}

void i_free()
{
	my_tab t = mindex(NULL);
	my_tapply(t, &i_free_el);
	my_tfree(t);
	mindex(my_tnew());
}

int i_count()
{
	return my_tlen(mindex(NULL));
}

char* i_getat(int i)
{
	my_tab t = mindex(NULL);
	struct el *e = my_tget(t, i);
	char *s = e->id;
	return s;
}
