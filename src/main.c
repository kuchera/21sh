#include "main.h"

int main()
{
	print_welcome();
	char *s;
	while (strcmp(s = my_readline(), "exit"))
	{
	}
	return 0;
}
