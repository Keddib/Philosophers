#include <unistd.h>
#include <sys/wait.h>
 #include <stdlib.h>
#include <stdio.h>
     #include <signal.h>
     #include <string.h>

int main(int c, char **v)
{
	pid_t pid;
	int status;
	
	status = 0;
	if (c > 2)
		return (0);
	if (c == 2)
		status = atoi(v[1]);
	pid = fork();
	if (pid == 0)
	{
		exit(0);
	}
	while (1)
	{}
	return (0);
}
