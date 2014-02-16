#include "fun_cat.h"
#include <stdio.h>


int fun_cat (int argc, char *argv[])
{
	if (argc == 1) 
    {
        printf("Aucun argument...\n");
        return 0;
    }
    
    int nb_arg = argc-1;
    while (nb_arg > 0)
    {   
        const char *filename =  argv[1];
        FILE *file = fopen(filename,"r");

        if (file != NULL)
        {   
            char line[128];
            while (fgets(line, sizeof(line), file) != NULL)
            {
               printf("%s ", line);
            }
            fclose(file);
        }
        else
        {
          perror(filename);
       }
       --nb_arg;
    }
    return 0;
}


