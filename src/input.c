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
	return t;
}
