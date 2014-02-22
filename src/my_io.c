#include "my_io.h"

int my_fprint(const char *file, FILE *out)
{
	FILE *f = fopen(file, "r");
	int c;
	if (!f)
		return -1;
	while ((c=fgetc(f)) != EOF)
		fputc(c, out);
	return fclose(f);
}

int my_fread(const char *file, char** out)
{
	FILE *f = fopen(file, "r");
	if (!f)
		return -1;
	long len =  my_fflen(f);
	*out = malloc((len + 1) * sizeof(char));
	**out = 0;
	char *c = strchr(*out, '\0');
	while (fgets(c, len, f))
		c = strchr(*out, '\0');
	return fclose(f);
}

int my_fwrite(const char *file, const char* str)
{
	if (!str)
		return 0;
	FILE* f = fopen(file, "w");
	if (!f)
		return -1;
	fputs(str, f);
	return fclose(f);
}

int my_fadd(const char *file, const char* str)
{
	if (!str)
		return 0;
	FILE* f = fopen(file, "a");
	if (!f)
		return -1;
	fputs(str, f);
	return fclose(f);
}

long my_flen(const char *file)
{
	FILE *f = fopen(file, "r");
	if (f)
		return my_fflen(f);
	return 0;
}

long my_fflen(FILE *file)
{
	fseek(file, 0, SEEK_END);
	long l = ftell(file);
	rewind(file);
	return l;
}
