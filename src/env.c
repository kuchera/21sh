#include "env.h"

char* prompts()
{
	char *p = pathtos(path(NULL));
	char *mess = my_strcat(p, " > ");
	free(p);
	return mess;
}

char* pathtos(my_tab t)
{
	char *s = my_smerge((char**)(t->tab), t->count, PATH_SEPARATORS);
	char *r = my_strcat(s, PATH_SEPARATORS);
	free(s);
	return r;
}

char* home()
{
	static char *path = NULL;
	if (!path)
		path = getenv("HOME");
	return path;
}

my_tab build_path(const char *path)
{
	int size;
	char **s = my_split(path, PATH_SEPARATORS, &size);
	return my_tbuild((void**)s, size);
}

my_tab path(my_tab path)
{
	static my_tab t = NULL;
	if (path)
		t = path;
	else if (!t)
		t = build_path(home());
	return t;
}

void path_add(const char *dir)
{
	my_tab t = path(NULL);
	my_tadd(t, my_stralloc(dir));
	path(t);
}

void path_up()
{
	if (my_tlen(path(NULL)) > 0)
	{
		my_tab t = path(NULL);
		my_tpop(t);
		path(t);
	}
}

void path_root()
{
	my_tab t = path(NULL);
	my_tapply(t, &free);
	my_tflush(t);
	my_tadd(t, my_stralloc(""));
}

int path_len()
{
	return my_tlen(path(NULL)) - 1;
}

void path_home()
{
	my_tab t = path(NULL);
	my_tapply(t, &free);
	my_tfree(t);
	path(build_path(home()));
}
