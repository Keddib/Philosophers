/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:48:24 by keddib            #+#    #+#             */
/*   Updated: 2021/09/26 10:28:11 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_taking_forks(t_philo *philo)
{
 	pthread_mutex_lock(&philo->data->forks[philo->ph_id]);
	pthread_mutex_lock(&philo->data->forks[(philo->ph_id + 1) % philo->data->n_philo]);
	pthread_mutex_lock(&philo->data->m_print);
	printf("%llu Philo %d : has taken a fork\n", get_time_in_ms() - philo->data->time, philo->ph_id + 1);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	philo_is_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	philo->last_eat = get_time_in_ms();
	printf("%llu Philo %d : is eating\n", get_time_in_ms() - philo->data->time, philo->ph_id + 1);
	pthread_mutex_unlock(&philo->data->m_print);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->ph_id]);
	pthread_mutex_unlock(&philo->data->forks[(philo->ph_id + 1) % philo->data->n_philo]);
}

void	philo_is_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	printf("%llu Philo %d : is sleeping\n", get_time_in_ms() - philo->data->time, philo->ph_id + 1);
	pthread_mutex_unlock(&philo->data->m_print);
	usleep(philo->data->time_eat * 1000);
}

void	philo_is_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->m_print);
	printf("%llu Philo %d : is thinking\n", get_time_in_ms() - philo->data->time, philo->ph_id + 1);
	pthread_mutex_unlock(&philo->data->m_print);
}

void	*philosopher(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		// take a fork
		ph_taking_forks(philo);
		// start earting; > when finish unlock fork;
		philo_is_eating(philo);
		// sleep ;
		philo_is_sleeping(philo);
		// then think;
		philo_is_thinking(philo);
		if (philo->data->is_philo_dead)
			break;
	}
	return NULL;
}
