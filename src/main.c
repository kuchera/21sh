#include "main.h"


///TEST
#include "match.h"
#include "input.h"
#include "my_tab.h"

int main(int argc, char **argv)
{
	if (argc == 2 && !strcmp(argv[1], "-t"))
	{
		my_tab t = read_command();
		my_tprint(t);
		puts("=========");
		match_quotes(t);
		my_tprint(t);
		return 0;
	}
	else
		return run(argc, argv);
}
