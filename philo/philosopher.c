/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:48:24 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 18:49:23 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->data->n_philo]);
	pthread_mutex_lock(&philo->data->forks[(philo->ph_id + 1) % philo->data->n_philo]);

	pthread_mutex_lock(&philo->data->forks[philo->data->n_philo]);
	printf("%llu Philo %d : has taken a fork\n", get_time_in_ms(), philo->ph_id + 1);
	pthread_mutex_unlock(&philo->data->forks[philo->data->n_philo]);
}

void	is_eating(t_philo *philo)
{
	philo->last_eat = get_time_in_ms();
	pthread_mutex_lock(&philo->data->forks[philo->data->n_philo]);
	printf("%llu Philo %d : is eating\n", get_time_in_ms(), philo->ph_id + 1);
	pthread_mutex_unlock(&philo->data->forks[philo->data->n_philo]);
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(&philo->data->forks[philo->ph_id]);
	pthread_mutex_unlock(&philo->data->forks[(philo->ph_id + 1) % philo->data->n_philo]);
}

void	*philosopher(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	// take a fork
	while (1)
	{
		take_forks(philo);
		// start earting; > when finish unlock fork;
		is_eating(philo);
		pthread_mutex_lock(&philo->data->forks[philo->data->n_philo]);
		printf("%llu Philo %d : is sleeping\n", get_time_in_ms(), philo->ph_id + 1);
		pthread_mutex_unlock(&philo->data->forks[philo->data->n_philo]);
		usleep(philo->data->time_eat * 1000);
		pthread_mutex_lock(&philo->data->forks[philo->data->n_philo]);
		printf("%llu Philo %d : is thinking\n", get_time_in_ms(), philo->ph_id + 1);
		pthread_mutex_unlock(&philo->data->forks[philo->data->n_philo]);
		// sleep ;
		// then think;
		// if (philo->data->is_philo_dead)
		// 	break;
	}
	return NULL;
}
