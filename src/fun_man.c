#include "fun_man.h"

int fun_man(int argc, char **argv)
{
	if (argc <= 1)
	{
		fputs("man : Not enough arguments\n", stderr);
		return NORESULTS21;
	}
	print_man(argv[1]);
	return SUCCESS21;
}
