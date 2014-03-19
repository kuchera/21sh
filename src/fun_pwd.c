#include "fun_pwd.h"

int fun_pwd(int argc, char **argv)
{
	char *s = pathtos(path(NULL));
	puts(s);
	free(s);
	return SUCCESS21;
	if (argc && argv) return 0;
}
