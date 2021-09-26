/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 16:48:24 by keddib            #+#    #+#             */
/*   Updated: 2021/09/26 17:55:11 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_taking_forks(t_philo *philo)
{
 	pthread_mutex_lock(&philo->data->forks[philo->ph_id]);
	pthread_mutex_lock(&philo->data->forks[(philo->ph_id + 1) % philo->data->n_philo]);
	print_philo_status(philo, 1);
}

void	philo_is_eating(t_philo *philo)
{
	print_philo_status(philo, 2);
	ms_sleep(philo->data->time_eat);
	pthread_mutex_unlock(&philo->data->forks[philo->ph_id]);
	pthread_mutex_unlock(&philo->data->forks[(philo->ph_id + 1) % philo->data->n_philo]);
	pthread_mutex_unlock(&philo->m_eat);
}

void	philo_is_sleeping(t_philo *philo)
{
	print_philo_status(philo, 3);
	ms_sleep(philo->data->time_sleep);
}

void	*philosopher(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (philo->data->is_philo_dead)
			break;
		// take a fork
		ph_taking_forks(philo);
		// start earting; > when finish unlock fork;
		philo_is_eating(philo);
		// sleep ;
		philo_is_sleeping(philo);
		// then think;
		print_philo_status(philo, 4);
	}
	return NULL;
}
