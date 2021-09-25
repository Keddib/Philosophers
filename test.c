#include <sys/time.h>
#include <stdio.h>

int main()
{
	struct timeval  tv;
	gettimeofday(&tv, NULL);

	double time_in_mill =
         (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ; // convert tv_sec & tv_usec to millisecond

	printf("%f\n", time_in_mill);
	return 0;
}