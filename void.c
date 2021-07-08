#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
  #include <sys/errno.h>
int main(int argc, char *argv[])
{
	pid_t pid;
	
	int *slep = malloc(sizeof(int) * argc);
	
	int status;

	int j = 1;
	
	while (j < argc)
	{
		slep[j - 1] = atoi(argv[j]);
		j++;
	}

	j = 0;
	int t = -1;
	for (int i = 0; i < argc - 1 ; i++)
	{
		j++;
		t++;
		pid = fork();
		if (pid == 0)
		{
			printf("child[%d]: %d started .. will sleep %d\n", j, getpid(), slep[t]);
			sleep((unsigned int)slep[i]);
			exit(0);
		}
		else
			continue;
	}
	j = 1;
	while (1)
	{
		pid = wait(&status);
		if (pid == -1) 
		{            
			if (errno == ECHILD)                 
			{
				printf("No more children - bye!\n");
				exit(0);
			}else
				exit(1);
		}
		printf("child finished %d   pid = %d\n", j, pid);
		j++;

	}
	pid = wait(&status);
	if (pid > 0)
		printf(" child finished %d\n", pid);
	exit(EXIT_SUCCESS);
}
