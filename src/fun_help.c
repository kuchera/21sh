#include "fun_help.h"

int fun_help(int argc, char **argv)
{
	if (argc > 1)
	{
		fputs("help : No arguments are accepted, try man\n", stderr);
		return NORESULTS21;
	}
	print_help();
	return 0;
	if (argv) return 0;
}
