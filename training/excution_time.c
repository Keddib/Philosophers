#include <stdio.h>
#include <time.h>

int main()
{
	pthread_mutex_t m;
	m = 
    clock_t t;
    t = clock();
 	// func
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("fun() took %f seconds to execute \n", time_taken);

	return (0);
}
