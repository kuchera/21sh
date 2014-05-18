#include "fun_ls.h"

static int max_size(my_tab t)
{
	int m = 0;
	int i, te;
	char *s;
	int len = my_tlen(t);

	for (i=0 ; i<len ; ++i)
	{
		s = my_tget(t, i);
		te = strlen(s);
		if (te > m)
			m = te;
	}

	return m;
}

static int console_width()
{
	struct winsize ws;
        ioctl(0, TIOCGWINSZ, &ws);
	return ws.ws_col;
}

static void print_sp(int n)
{
	while (n > 0)
	{
		putchar(' ');
		--n;
	}
}

static void print(char *s, int max, char *path)
{
	if (is_dir(path, s))
		printf(BLEUCLAIR "%s" NORMAL, s);
	else
		fputs(s, stdout);
	print_sp(max - strlen(s));
}

static void sexy_print(my_tab t)
{
        my_tsort(t);
	int max = max_size(t) + 2;
	if (max < 10)
		max = 10;
	int wid = console_width();
	int i = 0;
	int len = my_tlen(t);
	int col = wid / max;
	char *s;
	char *path = path_string();


	while (i < len)
	{
		s = my_tget(t, i);
		print(s, max, path);
		if ((i + 1) % col == 0 || i == len - 1)
			putchar ('\n');
		++i;
	}
	free(path);
}


int fun_ls(int argc, char **argv)
{
	char *p = pathtos(path(NULL));
	DIR *dir = opendir(p);
	int a;
	free(p);

	size_t i = 0;
	my_tab temp = my_tnew();

	if (!dir)
	{
		fprintf(stderr, "fun_ls : %s\n", strerror(errno));
		return UNEXPECTED21;
	}
	struct dirent *ent = readdir(dir);
	a = has_param(argc, argv, 'a');
	while (ent)
	{
		if (a || ent->d_name[0] != '.')
		{
			my_tadd(temp,(ent->d_name));
			//puts(my_tget(temp, i));
			i++;
		}
		ent = readdir(dir);
	}

	sexy_print(temp);

	
	closedir(dir);
	return SUCCESS21;
}
