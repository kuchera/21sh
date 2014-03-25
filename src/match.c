#include "match.h"

void match(my_tab argv)
{
	match_quotes(argv);
}

void match_quotes(my_tab tab)
{
	my_tab t = my_tnew();
	int isq = 0;
	char *s;
	char *s2;
	char *s3;
	size_t l;
	while (my_tlen(tab) > 0)
		my_tadd(t, my_tpop(tab));
	while (my_tlen(tab) > 0)
	{
		s = my_tpop(t);
		l = strlen(s) - 1;
		if (isq)
		{
			if (s[l] == '\"')
			{
				isq = 0;
				s[l] = 0;
			}
			s2 = my_tpop(tab);
			s3 = malloc(strlen(s) + strlen(s2) + 2);
			sprintf(s3, "%s %s", s, s2);
			free(s);
			free(s2);
			my_tadd(tab, s3);
		}
		else
		{
			if (*s == '\"')
			{
				isq = 1;
				++s;
				--l;
				if (s[l] == '\"')
				{
					isq = 0;
					s[l] = 0;
				}
			}
			my_tadd(tab, s);
		}
	}
}
