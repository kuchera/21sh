#include "fun_rm.h"

int fun_rm(int argc, char **argv)
{
	char *s;
	int i = 1, ret = 0, err = 0;
	while (i < argc)
	{
		s = my_strcat(path_string(), argv[i]);
		ret = unlink(s);
		if (ret)
		{
			err = errno;
			fprintf(stderr, "rm : %s\n", strerror(err));
		}
		free(s);
		++i;
	}
	return err;
}

