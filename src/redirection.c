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
	while (t != NULL);
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

int a_getout(my_tab t, my_tab out, my_tab err)
{
	int fd = -1;
	int *i;
	char *s = a_getff(t, ">>");
	while (s)
	{
		s = my_strcat(path_string(), s);
		fd = open(s, O_CREAT | O_WRONLY | O_APPEND, 0666);
		if (fd == -1)
			fprintf(stderr, "%s: %s\n", s, strerror(errno));
		else
		{
			i = malloc(sizeof(int));
			*i = fd;
			my_tadd(out, i);
		}
		free(s);
		s = a_getff(t, ">>");
	}
	a_getff(t, ">");
	while (s)
	{
		s = my_strcat(path_string(), s);
		fd = open(s, O_CREAT | O_WRONLY | O_TRUNC, 0666);
		if (fd == -1)
			fprintf(stderr, "%s: %s\n", s, strerror(errno));
		else
		{
			i = malloc(sizeof(int));
			*i = fd;
			my_tadd(out, i);
		}
		free(s);
		s = a_getff(t, ">");
	}
	return 0;
	if (err) return 0;
}
