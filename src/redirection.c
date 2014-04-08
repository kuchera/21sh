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
	int fd = 0;
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
		free(s);
		s = a_getff(t, sep);
	}
}

void a_getout(my_tab t, my_tab out, my_tab err)
{
	a_getoutf(t, out, 0, ">", 0);
	a_getoutf(t, out, 0, ">>", 1);
	a_getoutf(t, err, 0, "2>", 1);
	a_getoutf(t, err, out, "2>&1", 1);
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
	int ins = 0;
	int ret = 0;
	int *i;
	i = malloc(sizeof(int));
	*i = 1;
	my_tadd(outs, i);
	i = malloc(sizeof(int));
	*i = 2;
	my_tadd(errs, i);

	pid_t pid = fork();
	if (pid)
		waitpid(pid, NULL, 0);
	else
	{
		ins = a_getinf(t);
		a_getout(t, outs, errs);

		if (dup2(ins, 0) < 0)
			fprintf(stderr, "streams: dup: %s\n", strerror(errno));
		if (dup2(*((int*)my_tlast(outs)), 1) < 0)
			fprintf(stderr, "streams: dup: %s\n", strerror(errno));
		if (dup2(*((int*)my_tlast(errs)), 2) < 0)
			fprintf(stderr, "streams: dup: %s\n", strerror(errno));

		i_call(t);

		close(ins);
		my_tffree(outs, &a_free);
		my_tffree(errs, &a_free);
		exit(0);
	}
	return ret;
}

int is_redirect(my_tab t)
{
	int i = 0;
	int len = my_tlen(t);
	while (i < len)
	{
		if (strchr(my_tget(t, i), '>'))
			return 1;
		if (strchr(my_tget(t, i), '<'))
			return 1;
		if (strchr(my_tget(t, i), '|'))
			return 1;
		++i;
	}
	return 0;
}
