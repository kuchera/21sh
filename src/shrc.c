#include "shrc.h"

void shrc()
{
	char *file;
	if (my_fread(".21shrc", &file) != -1)
	{
		my_tab t = my_tsplit(file, "\n"), c;
		free(file);
		int i;
		for (i=0 ; i<my_tlen(t) ; ++i)
		{
			c = treat_command(my_tget(t, i));
			apply(c);
		}
	}
}
