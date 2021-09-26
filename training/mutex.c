/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:36:59 by keddib            #+#    #+#             */
/*   Updated: 2021/09/26 11:43:28 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

static int glob = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void my_usleep(unsigned long useconds)
{
	#if defined (ARMR5)
		usleep_R5(useconds);
	#elif defined (__aarch64__) || defined (ARMA53_32)
		usleep_A53(useconds);
	#elif defined (__MICROBLAZE__)
		usleep_MB(useconds);
	#else
		usleep_A9(useconds);
	#endif
}


void *thread_func(void *arg)
{
	int loops = *((int *) arg);
	int j;
	for (j = 0; j < loops; j++)
	{
		//lock mutex ;
		clock_t t;
    	t = clock();
		pthread_mutex_lock(&mutex);
		t = clock() - t;
		double time_taken = ((double)t)/CLOCKS_PER_SEC;
		printf("fun() took %f seconds to execute \n", time_taken);
		glob++;
		pthread_mutex_unlock(&mutex);
		// unlock mutex
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	// pthread_t t1, t2;
	int loops;

	loops = (argc > 1)? atoi(argv[1]) : 10000;
	// if (pthread_create(&t1, NULL, thread_func, &loops))
	// 	printf("create 1 Error\n");
	// // if (pthread_create(&t2, NULL, thread_func, &loops))
	// // 	printf("create 2 Error\n");
	// if (pthread_join(t1, NULL))
	// 	printf("join 1 Error\n");
	// if (pthread_join(t2, NULL))
	// 	printf("join 2 Error\n");
	my_usleep(1000 * 1000);
	// printf("glob = %d\n", glob);
	return(0);
}
