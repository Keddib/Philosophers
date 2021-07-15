#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>




int main()
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		printf("child process ...\n");
		//execve("/Users/keddib/goinfre/42/philosophers/hello", NULL, NULL);
		return (-1);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("s = %d\n", WEXITSTATUS(status));
		}
	}
	return (0);
}
