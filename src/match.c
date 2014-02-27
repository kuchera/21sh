#include "match.h"

void match_quotes(my_tab *tab)
{
	int i = 0;
	short cat = 0;
	char *s, *c;
	my_tab t = my_tnew();
	while (i < my_tlen(*tab))
	{
		s = my_tget(*tab, i);
		my_tadd(t, s);
		if (*s == '\"')
			cat = 1;
		if (cat)
		{
			c = my_tpop(t);
			my_tadd(t, my_strcat(c, s));
			free(c);
			free(s);
		}
		else
			my_tadd(t, s);
		if (s[strlen(s) - 1] == '\"')
			cat = 0;
		++i;
	}
	my_tfree(*tab);
	*tab = t;
}
