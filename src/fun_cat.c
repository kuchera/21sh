#include "fun_cat.h"

int fun_cat(int argc, char **argv, FILE* out, FILE* err)
{
	int i;
	int c;
	FILE *f;
	if (argc < 0)
	{
		fputs("fun_cat : Nombre d'arguments negatif", err);
		return -1;
	}
	for (i=1 ; i<argc ; ++i)
	{
		if (*(argv[i]) == '-')
		{
			// Args
		}
		else
		{
			f = fopen(argv[i], "r");
			if (!f)
				fprintf(err, "fun_cat : %s : %s\n", argv[i], strerror(errno));
			else
			{
				while ((c=fgetc(f)) != EOF)
					fputc(c, out);
				if (fclose(f))
					fprintf(err, "fun_cat : %s : %s\n", argv[i], strerror(errno));
			}
		}
	}
	return 0;
}
