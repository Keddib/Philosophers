/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exercise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 10:40:38 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 11:16:22 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void *routine(void *arg)
{
	int index = *(int *)arg;
	int sum = 0;
	for (int i = 0; i < 5; i++)
		sum += arr[index + i];
	*(int *)arg = sum;
	printf("pth sum = %d\n", sum);
	return (arg);
}

int main()
{
	pthread_t th[2];

	int sum  = 0;

	for (int i = 0; i < 2; i++)
	{
		int *a = malloc(1 * sizeof(int));
		*a = i * 5;
		if (pthread_create(&th[i], NULL, routine, a))
			return (1);
	}
	for (int i = 0; i < 2; i++)
	{
		void *r;
		if (pthread_join(th[i], &r))
			return (2);
		sum += *(int *)r;
		free(r);
	}
	printf("sum = %d\n", sum);
	return (0);
}
