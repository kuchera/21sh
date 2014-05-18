#include "fun_calc.h"

int fun_calc(int argc, char **argv)
{
	pid_t pid = fork();
	if (pid)
		waitpid(pid, NULL, 0);
	else
	{
		char *file = "/fun_calc";
		char **s = malloc((argc + 1) * sizeof(char*));
		s[0] = my_strcat(call_dir(), file);
		int i;
		for (i=1 ; i<argc ; ++i)
		{
			++argv;
			s[i] = my_strcat(path_string(), my_strcat("/", *argv));
		}
		s[argc] = NULL;
		execv(*s, s);
		fprintf(stderr, "calc: %s\n", strerror(errno));
		exit(0);
	}
	return 0;
}
