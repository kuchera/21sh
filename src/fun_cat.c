#include "fun_cat.h"

int fun_cat(int argc, char **argv)
{
	int i;
	int c;
	FILE *f;
	char *path;
	char *s = path_string();
	path = my_strcat(s, "/");
	free(s);
	for (i=1 ; i<argc ; ++i)
	{
			if (argv[i][0] != '/')
				s = my_strcat(path, argv[i]);
			else
				s = my_stralloc(argv[i]);
			f = fopen(s, "r");
			if (!f)
				fprintf(stderr, "fun_cat : %s : %s\n", argv[i], strerror(errno));
			else
			{
				while ((c=fgetc(f)) != EOF)
					putchar(c);
				if (fclose(f))
					fprintf(stderr, "fun_cat : %s : %s\n", argv[i], strerror(errno));
			}
			free(s);
	}
	free(path);
	return 0;
}
