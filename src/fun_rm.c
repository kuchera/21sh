#include "fun_rm.h"

int fun_rm(int argc, char **argv)
{
        
      if (argc > 1)
        {
            remove(argv[1]);
        }
        putchar('\n');
	
	return 0;
}

