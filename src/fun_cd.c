#include "fun_cd.h"

/*
int fun_cd (int argc, char **argv, FILE *out, FILE *err)
{
	if ((argc == 1)) 
    {
        printf("Aucun argument...\n");
        return 0;
    }
        
        char filename[255] =  "/home/archlinux/";
        DIR *directory = opendir(filename);
        
        if (directory != NULL)
        {   
            struct dirent *file = readdir(directory);
            
            while (file != NULL && (strcmp(file->d_name,argv[1])))
            {
                file = readdir(directory);
            }
            if (file == NULL)
            {
                printf("le dossier n'existe pas...\n");
            }
            else
            {
                strcat(filename,file->d_name);
                strcat(filename,"/");
            }

            closedir(directory);

        }
        else
        {
          perror(filename);
        }

    return 0;
}
*/
