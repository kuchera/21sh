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

static int a_contains(my_tab t, const char *s)
{
	int i = 0;
	while (i < my_tlen(t))
	{
		if (!strcmp(s, my_tget(t, i)))
			return i;
		++i;
	}
	return -1;
}

static int a_run(my_tab t, int out, int err, int in)
{
	
}

static int a_redirect(my_tab t)
{
	int os = -1;
	char *f, *ff;
	int i;

	while ((i = a_contains(t, ">")) > 0)
	{
		if (i + 2 != my_tlen(t))
		{
			if (os)
				close(os);
			ff = my_trmat(t, i+1);
			f = my_strcat(path_string(), ff);
			os = open(f, O_CREAT | O_WRONLY | O_TRUNC);
			free(f);
			if (!os)
			{
				fprintf(stderr, "%s : %s", ff, strerror(errno));
				return 1;
			}
		}
		my_trmat(t, i);
		oa = 0;
	}

	while ((i = a_contains(t, ">>")) > 0)
	{
		if (i + 2 != my_tlen(t))
		{
			if (os)
				close(os);
			ff = my_trmat(t, i+1);
			f = my_strcat(path_string(), ff);
			os = open(f, O_CREAT | O_WRONLY | O_TRUNC);
			free(f);
			if (!os)
			{
				fprintf(stderr, "%s : %s", ff, strerror(errno));
				return 1;
			}
		}
		my_trmat(t, i);
		oa = 0;
	}
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
		if (i != 0)
			break;
	}
	my_tfree(tc);
	return i;
}
