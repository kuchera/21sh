#include "fun_ls.h"

int fun_ls(int argc, char **argv, FILE *out, FILE *err)
{
	char *p = pathtos(path(NULL));
	DIR *dir = opendir(p);
	int a;
	free(p);
	if (!dir)
	{
		fprintf(err, "fun_ls : %s\n", strerror(errno));
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
			fputs(ent->d_name, out);
			fputc('\n', out);
		}
		ent = readdir(dir);
	}
	closedir(dir);
	return SUCCESS21;
}
