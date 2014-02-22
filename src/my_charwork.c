#include "my_charwork.h"

my_tab my_tsplit(const char *str, const char *sep)
{
	int i;
	char **t = my_split(str, sep, &i);
	return my_tbuild((void**)t, i);
}

char* my_tsmerge(my_tab t, const char *sep)
{
	return my_smerge((char**)(t->tab), t->count, sep);
}

char* my_smerge(char **tab, int size, const char *sep)
{
	if (size <= 0)
		return NULL;
	char *ret;
	long len = 1;
	int i = 0;
	for (i=0 ; i<size ; ++i)
		len += strlen(tab[i]);
	len += strlen(sep) * (size - 1);
	ret = malloc(len * sizeof(char));
	strcpy(ret, *tab);
	for (i=1 ; i<size ; ++i)
	{
		strcat(ret, sep);
		strcat(ret, tab[i]);
	}
	return ret;
}

char* my_strcat(const char *s1, const char *s2)
{
	char *ret = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	strcpy(ret, s1);
	return strcat(ret, s2);
}

char** my_split(const char* str, const char* sep, int *size)
{
	if (str == NULL || sep== NULL)
		return NULL;
	my_tab t = my_tnew();
	char *s = my_stralloc(str);
	int i;
	my_tadd(t, s);
	*size = 1;
	while (*s != '\0')
	{
		if (strchr(sep, *s))
		{
			*s = '\0';
			++s;
			my_tadd(t, s);
			++*size;
		}
		else
			++s;
	}
	char **tab = (char**)(t->tab);
	s = tab[0];
	for (i=0 ; i<*size ; ++i)
		tab[i] = my_stralloc(tab[i]);
	free(t);
	free(s);
	return tab;
}

char* my_stralloc(const char* str)
{
	if (str == NULL)
		return NULL;
	char* ret = malloc( (strlen(str) + 1) * sizeof(char));
	if (strcpy(ret, str))
		return ret;
	free(ret);
	return NULL;
}

char* my_readline()
{
	int c = getchar();
	size_t s = 20, i = 0;
	char *buf = malloc(s * sizeof(char));

	while (c != '\n' && c != EOF)
	{
		if (i == s - 1)
		{
			s *= 2;
			buf = realloc(buf, s * sizeof(char));
		}
		buf[i] = c;
		++i;
		c = getchar();
	}
	buf[i] = 0;
	return buf;
}

void my_clrbuf()
{
	int c = 0;
	while (c != '\n' && c != EOF)
		c = getchar();
}
