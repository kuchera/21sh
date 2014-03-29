#include "run.h"

int run(int argc, char **argv)
{
	if (argc >= 2)
        {
		my_tab t = my_tbuild((void**)(argv + 1), argc - 1);
		return apply(t);
        }

	print_welcome(); // Message de bienvenue
	my_tab t;
	while (1)
	{
		printf("%s", prompts());
		t = read_command();
		apply(t);
		my_tffree(t, &free);
	}
	return FATAL21;
	if (argc && argv) return 0;
}
