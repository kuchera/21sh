#include "env.h"

char* home()
{
	static char *path = NULL;
	if (!path)
		path = getenv("HOME");
	return path;
}
