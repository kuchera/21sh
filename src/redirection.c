#include "redirection.h"

char* a_getff(my_tab t, const char *sep)
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

int a_getinf(my_tab t)
{
	int fd = -1;
	char *s = NULL, *tmp = NULL;
	do
	{
		s = tmp;
		tmp = a_getff(t, "<");
	}
	while (tmp != NULL);
	if (s)
	{
		s = my_strcat(path_string(), s);
		fd = open(s, O_CREAT | O_RDONLY | O_APPEND, 0666);
		if (fd == -1)
			fprintf(stderr, "%s: %s\n", s, strerror(errno));
		free(s);
	}
	return fd;
}

void a_getoutf(my_tab t, my_tab out, my_tab out2, const char *sep, int append)
{
	char *s = a_getff(t, sep);
	int fd;
	int *i = NULL;
	while (s)
	{
		s = my_strcat(path_string(), s);
		if (append)
			fd = open(s, O_CREAT | O_WRONLY | O_APPEND, 0666);
		else
			fd = open(s, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (fd == -1)
			fprintf(stderr, "%s: %s\n", s, strerror(errno));
		else
		{
			i = malloc(sizeof(int));
			*i = fd;
			my_tadd(out, i);
			if (out2)
				my_tadd(out2, i);
		}
		puts(">>> OUT");
		if (i && *i)
			*i = write(*i, "test\n", 5);
		puts(s); // ====================
		free(s);
		s = a_getff(t, sep);
	}
}

void a_getout(my_tab t, my_tab out, my_tab err)
{
	a_getoutf(t, out, 0, ">", 0);
	a_getoutf(t, out, 0, ">>", 1);
	if (err) err = 0;
}

void a_free(void *e)
{
	int *fd = e;
	close(*fd);
	free(fd);
}

int redirect(my_tab t)
{
	my_tab outs = my_tnew();
	my_tab errs = my_tnew();
	int    ins = -1;
	int    ret = 0;

	ins = a_getinf(t);
	a_getout(t, outs, errs);

	ret = i_call(t); // fork()

	close(ins);
	my_tffree(outs, &a_free);
	my_tffree(errs, &a_free);
	return ret;
}
