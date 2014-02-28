#include "print.h"

void print_error(int erno)
{
	char s[30];
	if (snprintf(s, 30, "error_%d.txt", erno) <= 29)
		my_fprint(s, stdout);
}

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
