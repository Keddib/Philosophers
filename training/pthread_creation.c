/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread_creation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:39:47 by keddib            #+#    #+#             */
/*   Updated: 2021/09/24 17:36:39 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>


void *thread_func(void *arg)
{
	char *s = (char *) arg;
	printf("%s\n", s);
	sleep(3);
	printf("END OF THREAD\n");
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t t1, t2;
	char *loops = "Hello THREAD\n";

	if (pthread_create(&t1, NULL, thread_func, loops))
		printf("create 1 Error\n");
	if (pthread_create(&t2, NULL, thread_func, loops))
		printf("create 2 Error\n");
	if (pthread_join(t1, NULL))
		printf("join 1 Error\n");
	if (pthread_join(t2, NULL))
		printf("join 2 Error\n");
	return(0);
}
