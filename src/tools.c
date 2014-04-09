#include "tools.h"

int has_param(int argc, char **argv, char p)
{
	--argc;
	while (argc >= 0)
	{
		if (argv[argc] && argv[argc][0] && strchr(argv[argc], p))
			return 1;
		--argc;
	}
	return 0;
}
