#include "match.h"

void match(my_tab argv)
{
	match_quotes(argv);
}

void match_quotes(my_tab tab)
{
	my_tab t = my_tnew();
	char *s, *d;
	while (my_tlen(tab) > 0)
		my_tadd(t, my_tpop(tab));
	while (my_tlen(t) > 0)
	{
		s = my_tpop(t);
		if (s != NULL && s[0] == '\"')
		{
			strcpy(s, s+1);
			while (my_tlen(t) > 0 && s[strlen(s) - 1] != '\"')
			{
				d = my_tpop(t);
				s = realloc(s, strlen(s) + strlen(d) + 2);
				strcat(s, " ");
				strcat(s, d);
				free(d);
			}
			if (s[strlen(s) - 1] == '\"')
				s[strlen(s) - 1] = 0;
		}
		my_tadd(tab, s);
	}
	free(t);
}
