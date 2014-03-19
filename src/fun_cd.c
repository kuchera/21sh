#include "fun_cd.h"

static int fun_cd_exist(const char *s)
{
	char *pa = pathtos(path(NULL));
	DIR *dir = opendir(pa);
	free(pa);
	struct dirent *ent;
	do
		ent = readdir(dir);
	while (ent && strcmp(s, ent->d_name));
	closedir(dir);
	return ent != NULL;
}

static void fun_cd_move(const char *s)
{
	if (!strcmp(s, "")) // root
	{
		path_root();
	}
	else if (!strcmp(s, ".")); // current dir
	else if (!strcmp(s, "..")) // up
	{
		if (path_len() >= 1)
			path_up();
	}
	else if (!strcmp(s, "~")) // home
		path_home();
	else
		path_add(s);
}

int fun_cd(int argc, char **argv)
{
	if (argc <= 1)
	{
		if (path_len() >= 1)
			path_up();
		return SUCCESS21;
	}
	my_tab t = my_tsplit(argv[1], PATH_SEPARATORS);
	int i = 0;
	while (i < my_tlen(t))
	{
		if (	!strcmp("", my_tget(t, i)) || 
			!strcmp("~", my_tget(t, i)) ||
			fun_cd_exist(my_tget(t, i))  )
			fun_cd_move(my_tget(t, i));
		else
		{
			fputs("fun_cd : Directory doesn't exist\n", stderr);
			i = my_tlen(t);
		}
		++i;
	}
	my_tapply(t, &free);
	my_tfree(t);
	return SUCCESS21;
}
