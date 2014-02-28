#include "fun_pwd.h"

int fun_pwd(int argc, char **argv, FILE *out, FILE *err)
{
	char *s = pathtos(path(NULL));
	fputs(s, out);
	fputc('\n', out);
	free(s);
	return SUCCESS21;
	if (argc && argv && err) return 0;
}
