#include "command.h"

command c_parse(char * str)
{
	struct command *c = c_new();
	puts(str);
	return c;
}

void c_print(command c)
{
	int i = 0;
	if (c != NULL)
	{
		while (i < c->argc)
		{
			printf("%s ", c->argv[i]);
			++i;
		}
		printf("\n");
	}
}

void c_free(command c)
{
	c->argc -= 1;
	while (c->argc >= 0)
	{
		free(c->argv[c->argc]);
		c->argc -= 1;
	}
	free(c->argv);
	free(c);
}

command c_new()
{
	struct command *c = malloc(sizeof(struct command));
	c->argc = 0;
	c->argv = NULL;
	return c;
}
