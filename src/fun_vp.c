#include "fun_vp.h"

int fun_vp(int argc, char **argv)
{
	if (argc <= 1)
		return 0;
	pid_t pid = fork();
	if (pid)
		waitpid(pid, NULL, 0);
	else
	{
		char **s = malloc(argc * sizeof(char*));
		int i;
		for (i=0 ; i<argc - 1 ; ++i)
			s[i] = argv[i + 1];
		s[argc - 1] = NULL;
		execvp(*s, s);
		fprintf(stderr, "vp: %s\n", strerror(errno));
		exit(0);
	}
	return 0;
}
