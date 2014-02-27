#include "run.h"

int run(int argc, char **argv)
{
	print_welcome(); // Message de bienvenue
	i_init(); // Chargement des fonctiont dans l'index
	my_tab t;
	while (1)
	{
		printf("%s", prompts(NULL));
		t = read_command();
		i_call(t);
		my_tffree(t, &free);
	}
	return SUCCESS21;
	if (argc && argv) return 0;
}
