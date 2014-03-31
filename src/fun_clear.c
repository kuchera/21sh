#include "fun_clear.h"

int fun_clear(int argc, char **argv)
{
	printf("\033[H\033[2J");
	return 0;
	if (argc && argv) return 0;
}
