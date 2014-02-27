#include "fun_echo.h"

int fun_echo(int argc, char **argv, FILE* out, FILE* err)
{
	if (argc > 1) 
	{
    		int n = 2;
    		fprintf(out,"%s", argv[1]);
    		while (n < argc) 
		{
      			fprintf(out," %s", argv[n]);
      			n = n+1;
    		}
  	}
  	fprintf(out,"\n");
  	return 0;
}

