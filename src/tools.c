#include "tools.h"

int has_param(int argc, char **argv, char p)
{
	--argc;
	while (argc >= 0)
	{
		if (argv[argc] && argv[argc][0] && strchr(argv[argc], p))
			return 1;
		--argc;
	}
	return 0;
}

int is_dir(char *path, char *file)
{
        path = my_strcat(path, "/");
        file = my_strcat(path, file);

        struct stat *fichier = malloc(sizeof(struct stat));
        stat(file, fichier);
        int ret = S_ISDIR(fichier->st_mode);

        free(path);
        free(file);
        return ret;
}

int is_directory(char *file)
{
        struct stat *fichier = malloc(sizeof(struct stat));
        stat(file, fichier);
        return S_ISDIR(fichier->st_mode);
}
