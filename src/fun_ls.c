#include "fun_ls.h"

int fun_ls(int argc, char **argv)
{
	char *p = pathtos(path(NULL));
	DIR *dir = opendir(p);
	int a;
	free(p);
	if (!dir)
	{
		fprintf(stderr, "fun_ls : %s\n", strerror(errno));
		return UNEXPECTED21;
	}
	struct dirent *ent = readdir(dir);
	if (argc >= 2 && !strcmp(argv[1], "-a"))
		a = 1;
	else
		a = 0;
	while (ent)
	{
		if (a || ent->d_name[0] != '.')
		{
			puts(ent->d_name);
		}
		ent = readdir(dir);
	}
	closedir(dir);
	return SUCCESS21;
}
