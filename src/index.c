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

static void try_alias(my_tab t)
{
	my_tab a = i_alias(my_tget(t, 0), NULL);
	if (a)
	{
		my_trmat(t, 0);
		int i = my_tlen(a) - 1;
		while (i >= 0)
		{
			my_tinsert(t, my_tget(a, i), 0);
			--i;
		}
	}
}

// FUNCTIONS

my_tab i_alias(char *s, my_tab o)
{
	static my_tab a = NULL;
	if (!a)
		a = my_tnew();
	if (o)
	{
		void **p = malloc(2*sizeof(void*));
		*p = s;
		p[1] = o;
		my_tinsert(a, p, 0);
	}
	if (!s)
	{
		int i, j;
		void **p;
		for (i=0 ; i<my_tlen(a) ; ++i)
		{
			p = my_tget(a, i);
			s = *p;
			o = p[1];
			printf("%s = ", s);
			for (j=0 ; j<my_tlen(o) ; ++j)
				printf("%s ", (char*)(my_tget(o, j)));
			putchar('\n');
			
		}
		return NULL;
	}
	char *c;
	int i = 0;
	void **p;
	while (i < my_tlen(a))
	{
		p = my_tget(a, i);
		c = *p;
		if (!strcmp(s, c))
			return p[1];
		++i;
	}
	return NULL;
}

int i_call(my_tab args)
{
	if (my_tlen(args) <= 0)
		return 0;
	try_alias(args);
	command f = i_get(my_tget(args, 0));
	if (!f)
	{
		fprintf(stderr, "%s: No such function.\n", (char*)my_tget(args, 0));
		return NOSUCHFUNCTION21;
	}
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
