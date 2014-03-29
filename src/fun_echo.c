#include "fun_echo.h"

int fun_echo(int argc, char **argv)
{
	if (argc > 1) 
	{
    		int n = 1;
    		while (n < argc) 
		{
			if (n != 1)
				putchar(' ');
      			fputs(argv[n], stdout);
      			n = n+1;
    		}
  	}
	putchar('\n');
  	return 0;
}

