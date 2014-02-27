#include "fun_help.h"

int fun_help(int argc, char **argv, FILE *out, FILE *err)
{
	if (argc > 1)
	{
		fputs("help : No arguments are accepted, try man\n", err);
		return NORESULTS21;
	}
	print_help();
	return 0;
	if (argv && out) return 0;
}
