#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



int main ()
{
	pid_t pp, cp;
	int status;

	pp = fork();
	if (pp == 0)
	{
		cp = fork();
		if (cp == 0)
		{
			while (1)
				printf("ppid = %d\n", getppid());
			exit(0);
		}
		wait(&status);
		exit(status);
	}
	else
		sleep(1);
	return (0);
}
