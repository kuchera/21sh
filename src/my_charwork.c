#include "my_charwork.h"

my_list* my_split(const char* str, const char* separators)
{
	if (str == NULL || separators == NULL)
		return NULL;

	my_list* list= NULL;
	my_list* el = NULL;
	int i=0;
	
	while (str[i] != '\0')
	{
		if (my_strsearch(separators, &str[i]) >= 0)
		{
			if (el != NULL)
			{
				char* els;
				my_ltostr(el, &els);
				my_lfree(&el);
				my_ladd(&list, els);
				els = NULL;
				el = NULL;
			}
		}
		else
		{
			char* c = malloc(sizeof(char));
			*c = str[i];
			my_ladd(&el, c);
		}
		i++;
	}
	return list;
}

int my_rmata(char** str, int i)
{
	char* in = *str;
	int ret = my_rmat(in, str, i);
	free(in);
	return ret;
}

int my_rmat(const char* str, char** out, int i)
{
	if (str == NULL || i < 0)
		return -1;
	
	int length = my_strlen(str);
	int j=0;
	*out = malloc(length * sizeof(char));
	while (j < i)
	{
		(*out)[j] = str[j];
		j++;
	}
	while (j < length - 1)
	{
		(*out)[j] = str[j+1];
		j++;
	}
	return 0;
}

char* my_stralloc(const char* str)
{
	if (str == NULL)
		return NULL;

	char* ret = malloc( (my_strlen(str) + 1) * sizeof(char));
	int i=0;
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = str[i];
	return ret;
}

int my_rmstra(char** str, const char* rm)
{
	char* in = *str;
	int ret = my_rmstr(in, str, rm);
	free(in);
	return ret;
}

int my_rmstr(const char* str, char** out, const char* rm)
{
	if (rm == NULL || str == NULL)
		return -1;
	int i = 1;
	char* s = NULL;
	char* o = NULL;
	my_rmchar(str, &s, rm[0]);

	while (rm[i] != '\0')
	{
		my_rmchar(s, &o, rm[i]);
		free(s);
		s = o;
		o = NULL;
		i++;
	}
	out = &s;
	return 0;
}

int my_rmchara(char** str, char c)
{
	char* in = *str;
	int ret = my_rmchar(in, str, c);
	free(in);
	return ret;
}

int my_rmchar(const char* str, char** out, char c)
{
	if (str == NULL)
		return -1;
	
	int count = 0;
	int i = 0;
	while (str[i + count] != '\0')
	{
		if (str[i + count] == c)
			count++;
		else
			i++;
	}
	*out = malloc( (i + 1) * sizeof(char));
	i = 0;
	count = 0;
	while (str[count + i] != '\0')
	{
		if (str[i + count] == c)
			count++;
		else
		{
			(*out)[i] = str[i + count];
			i++;
		}
	}
	(*out)[i] = '\0';
	return 0;
}

int my_substr(const char *str, char** out, int start, int length)
{
	if (start < 0 || length <= 0)
		return -1;

	*out = malloc(length * sizeof(char));
	int i=0;
	while (i < length && str[start + i] != '\0')
	{
		(*out)[i] = str[start + i];
		i++;
	}
	(*out)[i] = '\0';
	return 0;
}

int my_substra(char** str, int start, int end)
{
	char* in = *str;
	int ret = my_substr(in, str, start, end);
	free(in);
	return ret;
}

int my_strcat(char **string, const char *s1, const char *s2)
{
	int l1 = my_strlen(s1), l2 = my_strlen(s2), i;
	*string = malloc((l1 + l2 + 1) * sizeof(char));

	if (*string == NULL)
		return -1;

	i = 0;
	if (s1 != NULL)
	{
		while (i < l1)
		{
			(*string)[i] = s1[i];
			i++;
		}
	}
	i = 0;
	if (s2 != NULL)
	{
		while (i < l2)
		{
			(*string)[l1 + i] = s2[i];
			i++;
		}
	}
	(*string)[l1 + l2] = '\0';

	return 1;
}

void my_readline(char **string)
{
	my_list *l = NULL;
	int* p = NULL;
	int c = getchar();

	while (c != '\n' && c != EOF)
	{
		p = malloc(sizeof(int));
		*p = c;
		my_ladd(&l, p);
		c = getchar();
	}

	my_ltostr(l, string);
	my_lfree(&l);
}

void my_clrbuf()
{
	int c = 0;
	while (c != '\n' && c != EOF)
		c = getchar();
}

int my_strlen(const char* str)
{
	if (str == NULL)
		return 0;
	int i=0;
	while (str[i] != '\0')
		i++;
	return i;
}

void my_ltostr(const my_list* l, char** out)
{
	if (l != NULL)
	{
		int len = my_llen(l), i;
		*out = malloc((len + 1) * sizeof(char));
		i = 0;
		while (i < len)
		{
			(*out)[i] = *(char*)my_leltat(l, i);
			i++;
		}
		(*out)[len] = '\0';
	}		
}

int my_strsearch(const char *str, const char *c)
{
	if (str == NULL)
		return -1;
	int i=0;
	while (str[i] !='\0' && str[i] != *c)
		i++;
	if (str[i] == '\0')
		return -1;
	else
		return i;
}
