/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:37:05 by keddib            #+#    #+#             */
/*   Updated: 2021/09/26 17:34:59 by keddib           ###   ########.fr       */
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
	data.time = get_time_in_ms();
	create_philos(&data, philo, thread, 0);
	usleep(1000);
	create_philos(&data, philo, thread, 1);

	uint64_t now, strv;
	int n_must_eat;

	while (1)
	{
		n_must_eat = 0;
		for (int i = 0; i < data.n_philo; i++)
		{
			now = get_time_in_ms();
			// printf("now = %llu\n", now);
			// printf("last = %llu\n", philo[i].last_eat);
			strv = now - philo[i].last_eat;
			// printf("strv = %llu\n", strv);

			// printf("t_die = %llu\n", (uint64_t)data.time_die);
			pthread_mutex_lock(&philo[i].m_eat);
			if (strv > (uint64_t)data.time_die)
			{
				//
				printf("%.6llu Philo %.3d : died\n", get_time_in_ms() - data.time, philo[i].ph_id + 1);
				data.is_philo_dead = 1;
				return (0);
			}
			pthread_mutex_unlock(&philo[i].m_eat);
			n_must_eat++;
		}
		usleep(1e3);
		// if must eat == n_philo that means all philos reached the n must eat;
	}
	return (0);
}
