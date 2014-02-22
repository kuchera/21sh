#include "print.h"

void print_welcome()
{
	my_fprint("welcome.txt", stdout);
}

void print_help()
{
	my_fprint("help.txt", stdout);
}

void print_man(const char *id)
{
	char *f = malloc((strlen(id) + 14) * sizeof(char));
	strcpy(f, "fun_");
	strcat(f, id);
	strcat(f, "_help.txt");
	my_fprint(f, stdout);
	free(f);
}
