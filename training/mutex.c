/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:36:59 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 10:00:33 by keddib           ###   ########.fr       */
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

void *thread_func(void *arg)
{
	int loops = *((int *) arg);
	int j;
	for (j = 0; j < loops; j++)
	{
		//lock mutex ;
		pthread_mutex_lock(&mutex);
		glob++;
		pthread_mutex_unlock(&mutex);
		// unlock mutex
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	int loops;

	loops = (argc > 1)? atoi(argv[1]) : 10000;
	if (pthread_create(&t1, NULL, thread_func, &loops))
		printf("create 1 Error\n");
	if (pthread_create(&t2, NULL, thread_func, &loops))
		printf("create 2 Error\n");
	if (pthread_join(t1, NULL))
		printf("join 1 Error\n");
	if (pthread_join(t2, NULL))
		printf("join 2 Error\n");

	printf("glob = %d\n", glob);
	return(0);
}
