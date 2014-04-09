#include "fun_ls.h"

static void sexy_print(my_tab t)
{
     if(t->count >0)
     {
        my_tsort(t);
        size_t taillemax = 0;
        int i, j;
        size_t k;

        for(i = 0; i < t->count; i++)
                if (taillemax < strlen((t->tab[i])))
                        taillemax = strlen((t->tab[i]));
	
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
        int nb_columns = w.ws_col;
        if (nb_columns < 70)
                my_tprint(t);

        else
        {
        int nb_to_print = (nb_columns / taillemax)-1;


        //printf("%d\t%d\t%d",taillemax, nb_columns, nb_to_print);

         for (i = 0; i < (t->count)-1;)
         {
	      if ( t->tab[i])
               {
		for (j = 0; j < nb_to_print-1 && t->tab[i] != NULL;j++)
                {
			if(is_directory(t->tab[i]))
				printf(BLEU "%s"NORMAL,(char*)(t->tab[i]));
			else
                        	printf("%s",(char*)(t->tab[i]));
                        if (strlen((t->tab[i])) < taillemax)
                                for(k = strlen((t->tab[i])); k < taillemax;k++)
                                        printf(" ");

                        printf("  ");
                        i++;
                }
                printf("\n");
	       }
		else
		 i= (t->count);
         }

        }
      }
}


int fun_ls(int argc, char **argv)
{
	char *p = pathtos(path(NULL));
	DIR *dir = opendir(p);
	int a;
	free(p);

	size_t i = 0;
	my_tab temp = my_tnew();

	if (!dir)
	{
		fprintf(stderr, "fun_ls : %s\n", strerror(errno));
		return UNEXPECTED21;
	}
	struct dirent *ent = readdir(dir);
	if (argc >= 2 && !strcmp(argv[1], "-a"))
		a = 1;
	else
		a = 0;
	while (ent)
	{
		if (a || ent->d_name[0] != '.')
		{
			my_tadd(temp,(ent->d_name));
			//puts(my_tget(temp, i));
			i++;
		}
		ent = readdir(dir);
	}

	sexy_print(temp);

	
	closedir(dir);
	return SUCCESS21;
}
