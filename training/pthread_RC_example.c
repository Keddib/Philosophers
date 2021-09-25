/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_RC_example.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:39:47 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 08:22:26 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

static int glob = 0;

void *thread_func(void *arg)
{
	int loops = *((int *) arg);
	int j;
	for (j = 0; j < loops; j++)
		glob++;
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
