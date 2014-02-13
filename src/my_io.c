#include "my_io.h"

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
	if (str == NULL)
		return 0;
	FILE* f = fopen(file, "w");
	if (f == NULL)
		return EOF;
	fputs(str, f);
	return fclose(f);
}

int my_fadd(const char *file, const char* str)
{
	if (str == NULL)
		return 0;
	FILE* f = fopen(file, "a");
	if (f == NULL)
		return EOF;
	fputs(str, f);
	return fclose(f);
}

long my_flen(const char *file)
{
	FILE *f = fopen(file, "r");
	if (f != NULL)
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

/*      MEMO
        int fputc(int caractere, FILE* pointeurSurFichier);
        char* fputs(const char* chaine, FILE* pointeurSurFichier);
        int fprintf ( FILE * stream, const char * format, ... );

        int fgetc(FILE* pointeurDeFichier);
        char* fgets(char* chaine, int nbreDeCaracteresALire, FILE* pointeurSurFichier);
        int fscanf ( FILE * stream, const char * format, ... );

        int fseek(FILE* pointeurSurFichier, long deplacement, int origine);
        long ftell(FILE* pointeurSurFichier);
        SEEK_SET SEEK_CUR SEEK_END
        void rewind(FILE* pointeurSurFichier);
        
        int rename(const char* ancienNom, const char* nouveauNom);
        int remove(const char* fichierASupprimer);
*/

