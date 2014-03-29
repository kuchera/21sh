#include "apply.h"

// === STATIC ===

static my_tab a_cp(my_tab t)
{
	my_tab tt = my_tnew();
	int i;
	for (i=0 ; i< my_tlen(t) ; ++i)
		my_tadd(tt, my_tget(t, i));
	return tt;
}

static my_tab a_first(my_tab t, const char *sep)
{
	my_tab tt = my_tnew();
	char *s;
	while (my_tlen(t) > 0)
	{
		s = my_trmat(t, 0);
		if (!strcmp(sep, s))
			return tt;
		my_tadd(tt, s);
	}
	return tt;
}

// === FUNCTIONS ===

int apply(my_tab t)
{
	my_tab tt = NULL;
	my_tab tc = a_cp(t);;
	int i = 0;
	while (my_tlen(tc) > 0)
	{
		tt = a_first(tc, ";");
		i = i_call(tt);
		if (i == NOSUCHFUNCTION21)
			puts("No such function.");
		my_tfree(tt);
	}
	my_tfree(tc);
	return i;
}
