#include "fun_rm.h"

int fun_rm(int argc, char **argv)
{
	char *s;
	int recursive = has_param(argc, argv, 'r');
	int i = 1, ret = 0, err = 0;
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			s = my_strcat(path_string(), argv[i]);
			ret = 0;
			if (recursive || !is_directory(s))
				ret = remove(s);
			else
				fprintf(stderr, "rm : %s est un dossier\n", s);
			if (ret)
			{
				err = errno;
				fprintf(stderr, "rm : %s\n", strerror(err));
			}
			free(s);
		}
		++i;
	}
	return err;
}

