/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:18:12 by keddib            #+#    #+#             */
/*   Updated: 2021/09/27 14:50:31 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_num_of_eats(t_philo *philo, int num_eat)
{
	int	i;

	i = 0;
	if (philo[0].data->n_time_must_eat)
	{
		while (i < philo[0].data->n_philo)
			if (num_eat > philo[i++].n_time_eats)
				return (0);
	}
	else
		return (0);
	return (1);
}

int	supervisor(t_philo *philo, t_data data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data.n_philo)
		{
			pthread_mutex_lock(&philo[i].m_eat);
			if ((get_time_in_ms() - philo[i].last_eat)
				> (uint64_t)data.time_die)
			{
				pthread_mutex_lock(&philo[i].data->m_print);
				g_is_philo_dead = 1;
				printf("%.6llu Philo %.3d : died\n", get_time_in_ms()
					- data.time, philo[i].ph_id + 1);
				return (1);
			}
			pthread_mutex_unlock(&philo[i++].m_eat);
		}
		if (check_num_of_eats(philo, data.n_time_must_eat))
			return (1);
		usleep(1e3);
	}
	return (0);
}
