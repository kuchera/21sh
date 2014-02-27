#include "fun_exit.h"

int fun_exit(int argc, char **argv, FILE *out, FILE *err)
{
	exit(0);
	return 0;
	if (argc && argv && out && err) exit(0);
}
