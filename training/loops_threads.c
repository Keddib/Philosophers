/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:22:17 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 10:32:48 by keddib           ###   ########.fr       */
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
	pthread_t th[8];
	int loops;

	loops = (argc > 1)? atoi(argv[1]) : 10000;

	for (int i = 0; i < 8; i++)
	{
		if (pthread_create(&th[i], NULL, thread_func, &loops))
			printf("create 1 Error\n");
		printf("thread nu %d has started\n", i);
	}
	for (int i = 0; i < 8; i++)
	{
		if (pthread_join(th[i], NULL))
			printf("join 1 Error\n");
		printf("thread nu %d has finished\n", i);
	}
	printf("glob = %d\n", glob);
	return(0);
}
