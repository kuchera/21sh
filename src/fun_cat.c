#include "fun_cat.h"

int fun_cat(int argc, char **argv, FILE* out, FILE* err)
{
	int i;
	int c;
	FILE *f;
	char *path;
	char *s = path_string();
	path = my_strcat(s, "/");
	free(s);
	if (argc < 0)
	{
		fputs("fun_cat : Nombre d'arguments negatif", err);
		return -1;
	}
	for (i=1 ; i<argc ; ++i)
	{
			s = my_strcat(path, argv[i]);
			f = fopen(s, "r");
			if (!f)
				fprintf(err, "fun_cat : %s : %s\n", argv[i], strerror(errno));
			else
			{
				while ((c=fgetc(f)) != EOF)
					fputc(c, out);
				if (fclose(f))
					fprintf(err, "fun_cat : %s : %s\n", argv[i], strerror(errno));
			}
			free(s);
	}
	free(path);
	return 0;
}
