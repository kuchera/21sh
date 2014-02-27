#include "main.h"

int main(int argc, char **argv)
{
	if (argc == 2 && !strcmp(argv[1], "-t"))
	{
		puts(prompts(NULL));
		return 0;
	}
	else
		return run(argc, argv);
}
