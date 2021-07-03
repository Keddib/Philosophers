#include <unistd.h>
#include <string.h>
#include <fcntl.h>
     #include <sys/types.h>
     #include <sys/uio.h>


int main(int argc, char **argv)
{
	int input;
	int output;
	int ret;
	char buf[1024];

	if (argc != 3 || strcmp(argv[1], "--help") == 0)
	{
		write(2, "copy [old-file] [new-file]\n", 27); 
		return (1);
	}
	input = open(argv[1], O_RDONLY);
	if (input == -1)
	{
		write(2, "open file input\n", 16);
		return (1);
	}
	output = open (argv[2], O_CREAT | O_WRONLY | O_APPEND, 0666); 
	if (output == -1)
	{
		write(1, "opening file output\n", 19);
		return (1);
	}
	while ((ret = read(input, buf, 1024)) > 0)
		write(output, buf, ret);
	if (ret == -1)
		write(2, "READ ERR\n", 9);
	if (close(input) == -1)
		write(2, "CLOSE IN\n", 9);
	if (close(output) == -1)
		write(2, "CLOSE OUT\n", 10);
	return (0);
}
