#include "my_charwork.h"

char** my_split(const char* str, const char* sep, int *size)
{
	if (str == NULL || sep== NULL)
		return NULL;
	my_list l = NULL;
	char *s = my_stralloc(str);
	my_ladd(&l, s);
	*size = 1;
	while (*s != '\0')
	{
		if (strchr(sep, *s))
		{
			*s = '\0';
			++s;
			my_ladd(&l, s);
			++*size;
		}
		else
			++s;
	}
	char **t = my_ltoarray(l);
	my_lfree(&l);
	return t;
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
