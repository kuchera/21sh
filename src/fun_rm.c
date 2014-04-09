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
			if (recursive)
				ret = remove(s);
			else
				ret = unlink(s);
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

