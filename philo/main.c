/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:37:05 by keddib            #+#    #+#             */
/*   Updated: 2021/09/26 10:29:22 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	int			i;
	t_data		data;
	pthread_t	*thread;
	t_philo		*philo;

	i = 0;
	if (check_args(++argv, argc, &data))
		return (1);
	thread = (pthread_t *)malloc(data.n_philo * sizeof(pthread_t));
	philo = (t_philo *)malloc(data.n_philo * sizeof(t_philo));
	while (i < data.n_philo)
	{
		// init philo_id with i;
		philo[i].ph_id = i;
		philo[i].n_time_eats = 0;
		//init philo->data with data adress;
		philo[i].data = &data;
		pthread_create(&thread[i], NULL, philosopher, (void *)&philo[i]);
		i++;
	}
	while (1)
	{
		// for (int i = 0; i < data.n_philo; i++)
		// {
			//must eat ++;
		// 	if ((get_time_in_ms() - ph_status[i].last_eat) > (unsigned long long)data.time_die)
		// 	{
		// 		printf("%llu Philo %d : died\n", get_time_in_ms(), ph_status[i].ph_id + 1);
		// 		data.is_philo_dead = 1;
		// 	}
		// }
		// if must eat == n_philo that means all philos reached the n must eat;
	}
	return (0);
}
