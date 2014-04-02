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

static char* a_getff(my_tab t, const char *sep)
{
	int i = 0;
	char *s = NULL;
	while (i < my_tlen(t))
	{
		if (!strcmp(my_tget(t, i), sep))
		{
			my_trmat(t, i);
			if (i < my_tlen(t))
				return my_trmat(t, i);
		}
		++i;
	}
	return s;
}

static int a_getout(my_tab t)
{
	int fd = -1;
	char *s = a_getff(t, ">>");
	if (s)
	{
		s = my_strcat(path_string(), s);
		fd = open(s, O_CREAT | O_WRONLY | O_APPEND, 0666);
		if (fd == -1)
			fprintf(stderr, "%s: %s\n", s, strerror(errno));
		free(s);
	}
	return fd;
}

static int a_redirect(my_tab t)
{
	int ret = 0;
	int fd = a_getout(t);
	if (fd >= 0)
	{
		ssize_t w = write(fd, "coucou\n", 7); if (!w) w=0;
		close(fd);
	}
	return ret;
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
		a_redirect(tt); // TEST
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
