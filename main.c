#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	pid_t	pid;
	int		status;


	if (argc < 2)
		return (0);
	status = 0;
	argv++;
	pid = fork();
	if (pid == 0)
	{
		puts("Child process running ...\n");
		execve(argv[0], argv, NULL);
		exit(20);
	}
	else
	{
		wait(&status);
		puts("Parent process running ...\n");
		printf("status = %d\n", status);
	}
	return (0);
}
