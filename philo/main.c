/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:37:05 by keddib            #+#    #+#             */
/*   Updated: 2021/09/27 13:14:49 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philos(t_data *data, t_philo *philo, pthread_t *thread, int i)
{
	while (i < data->n_philo)
	{
		philo[i].ph_id = i;
		philo[i].last_eat = data->time;
		philo[i].n_time_eats = 0;
		pthread_mutex_init(&philo[i].m_eat, NULL);
		philo[i].data = data;
		pthread_create(&thread[i], NULL, philosopher, (void *)&philo[i]);
		i += 2;
	}
}

int	main(int argc, char *argv[])
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
	data.time = get_time_in_ms();
	create_philos(&data, philo, thread, 0);
	usleep(1000);
	create_philos(&data, philo, thread, 1);
	supervisor(philo, data);
	free(data.forks);
	free(thread);
	free(philo);
	return (0);
}
