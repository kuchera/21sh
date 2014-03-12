#include "run.h"

int run(int argc, char **argv)
{
	print_welcome(); // Message de bienvenue
	i_init(); // Chargement des fonctiont dans l'index
	my_tab t;
	int i;
	while (1)
	{
		printf("%s", prompts());
		t = read_command();
		i = i_call(t);
		if (i == NOSUCHFUNCTION21)
			fputs("Function doesn't exist\n", stderr);
		my_tffree(t, &free);
	}
	return SUCCESS21;
	if (argc && argv) return 0;
}
