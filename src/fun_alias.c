#include "fun_alias.h"

int fun_alias(int argc, char **argv)
{
	if (argc == 1)
	{
		i_alias(NULL, NULL);
		return 0;
	}
	if (argc < 3)
	{
		fprintf(stderr, "alias: not enough arguments\n");
		return NORESULTS21;
	}
	my_tab t = my_tsplit(argv[2], " ");
	i_alias(my_stralloc(argv[1]), t);
	return 0;
}
