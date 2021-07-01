#include <unistd.h>
     #include <sys/wait.h>
		#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc < 2)
		return 0;
	
	pid_t pid;
	int ex = 10;
	
	pid = fork();
	
	if (pid > 0)
	{
		execv(argv[1], argv + 1);
	}
	else
		return (1);
	waitpid(pid, &ex, 0);
	return (10);
}
