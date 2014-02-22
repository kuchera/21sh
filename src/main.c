#include "main.h"

int main()
{
	path(build_path(home()));
	path_add("dirdir");
	my_tprint(path(NULL));
	return 0;
}
