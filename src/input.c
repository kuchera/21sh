#include "input.h"

char* read_input()
{
	return my_readline();
}

my_tab read_command()
{
	char *s = read_input();
	my_tab t = my_tsplit(s, " ");
	free(s);
	int i = 0;
	while (i < my_tlen(t))
	{
		if (!strcmp("", my_tget(t, i)))
			free(my_trmat(t, i));
		else
			++i;
	}
	match(t);
	return t;
}
