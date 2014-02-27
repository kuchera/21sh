#include "run.h"

int run()
{
	print_welcome();
	my_tab t;
	while (1)
	{
		t = read_command();
		i_call(t);
		my_tffree(t, &free);
	}
	return 0;
}
