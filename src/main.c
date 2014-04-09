#include "main.h"

#include <string.h>
#include <errno.h>
#include "input.h"
#include "my_tab.h"

int main(int argc, char **argv)
{
	i_init(); // Initialisation de l'index de fonctions
	if (argc == 2 && !strcmp(argv[1], "-t"))
	{
		puts("=== TESTS ===");
		return 0;
	}
	else
		return run(argc, argv);
}
