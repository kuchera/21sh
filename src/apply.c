#include "apply.h"

int apply(my_tab t)
{
	int i = i_call(t);
	if (i == NOSUCHFUNCTION21)
		puts("No such function.");
	return i;
}
