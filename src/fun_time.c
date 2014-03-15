#include "fun_time.h"

int fun_time(int argc, char **argv, FILE *out, FILE *err)
{
	if (argc <= 1)
		return NORESULTS21;
	command f = i_get(argv[1]);
	if (!f)
		return NOSUCHFUNCTION21;
	struct timespec ts, te;
	pid_t pid = fork();
	if (pid == -1)
	{
		fprintf(err, "fun_time : fork : %s\n", strerror(errno));
		return FATAL21;
	}
	if (pid)
	{
		clock_gettime(CLOCK_REALTIME, &ts);
		waitpid(pid, NULL, 0);
		clock_gettime(CLOCK_REALTIME, &te);
	}
	else
	{
		command f = i_get(argv[1]);
		(*f)(argc-1,argv+1,out,err);
		exit(0);
	}
	long diff = te.tv_nsec - ts.tv_nsec;
	fprintf(out, "%ld\n", diff);
	return SUCCESS21;
}
