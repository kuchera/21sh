#include "main.h"

#include "input.h"
#include "my_tab.h"

int main(int argc, char **argv)
{
	if (argc == 2 && !strcmp(argv[1], "-t"))
	{
		puts("=== TESTS ===");
		my_tab t = read_command();
		printf("argc: %d\n", my_tlen(t));
		match(t);
		printf("argc: %d\n", my_tlen(t));
		my_tprint(t);
		return 0;
	}
	else
		return run(argc, argv);
}
