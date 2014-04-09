#include "fun_mkdir.h"

int fun_mkdir(int argc, char **argv)
{
	char *p = path_string();
	char *s;
	int i;
	int ret = 0;
	for (i=1 ; i<argc ; ++i)
	{
	 	s = my_strcat(p, argv[i]);
		if (mkdir(s, 0777))
		{
			ret = errno;
			fprintf(stderr, "mkdir: %s\n", strerror(errno));
		}
		free(s);
	}
	free(p);
	return ret;
}
