#include "run.h"

int run(int argc, char **argv)
{
	i_init(); // Chargement des fonctiont dans l'index
	if (argc >= 2)
        {
                command f = i_get(argv[1]);
                if (!f)
                        printf("No such command : %s\n", argv[1]);
                else
                        (*f)(argc-1, argv+1, stdout, stderr);
		exit(0);
        }

	print_welcome(); // Message de bienvenue
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
