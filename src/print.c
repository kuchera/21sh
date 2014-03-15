#include "print.h"


void print_welcome()
{
	my_fprint("welcome.txt", stdout);
}

void print_help()
{
	char *s;
	int i;
	for (i=0 ; i<i_count() ; ++i)
	{
		s = i_getat(i);
		print_desc(s);
	}
}

void print_desc(const char *id)
{
	char *s = my_strcat("fun_", id);
	char *d = my_strcat(s, "_help.txt");
	free(s);
	FILE *f = fopen(d, "r");
	free(d);
	if (f)
	{
		char c = getc(f);
		while (c != EOF && c != '\n')
			c = getc(f);
		if (c != EOF)
		{
			c = getc(f);
			while (c != EOF && c != '\n')
			{
				putchar(c);
				c = getc(f);
			}
			putchar('\n');
		}
		fclose(f);
	}
	else
		putchar('\n');
}

void print_man(const char *id)
{
	char *f = malloc((strlen(id) + 14) * sizeof(char));
	strcpy(f, "fun_");
	strcat(f, id);
	strcat(f, "_help.txt");
	if (my_fprint(f, stdout))
		puts("No manual for this command");
	free(f);
}
