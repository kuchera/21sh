#include "index.h"

struct el
{
	command c;
	int (*f)(int, char**);
};

static my_list index(my_list l)
{
	static my_list i = NULL;
	if (l != NULL)
		i = l;
	return i;
}

void i_add(command c, int (*f)(int, char**))
{
	struct el *e = malloc(sizeof(struct el));
	e->c = c;
	e->f = f;
	my_list l = index(NULL);
	my_ladd(&l, e);
	index(l);
}

static void i_free_el(void *e)
{
	struct el *ele = e;
	c_free(ele->c);
	free(ele);
}

void i_free()
{
	my_list l = index(NULL);
	my_lapply(l, &i_free_el);
	my_lfree(&l);
	index(l);
}

int i_count()
{
	return my_llen(index(NULL));
}
