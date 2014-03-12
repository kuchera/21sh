#include "fun_man.h"

int fun_man(int argc, char **argv, FILE *out, FILE *err)
{
	if (argc <= 1)
	{
		fputs("man : Not enough arguments\n", err);
		return NORESULTS21;
	}
	print_man(argv[1]);
	return SUCCESS21;
	if (out) return 0;
}
