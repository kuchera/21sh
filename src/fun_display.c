#include "fun_display.h"

int fun_display(int argc, char **argv)
{
	pid_t pid = fork();
	if (pid)
		waitpid(pid, NULL, 0);
	else
	{
		char *file = "fun_display";
		exit(0);
	}
	return 0;
}
