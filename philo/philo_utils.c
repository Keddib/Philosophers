/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:54:41 by keddib            #+#    #+#             */
/*   Updated: 2021/09/27 13:05:05 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ms_sleep(uint64_t time_eat)
{
	uint64_t lasttime;

	lasttime = get_time_in_ms();
	usleep((time_eat * 1000) - 20000);
	while ((get_time_in_ms() - lasttime) < time_eat)
		continue;
}

void	print_philo_status(t_philo *philo, int msg)
{
	uint64_t time;
	char *message;

	if (msg == 1)
		message = "has taken a fork";
	else if (msg == 2)
		message = "is eating";
	else if (msg == 3)
		message = "is sleeping";
	else if (msg == 4)
		message = "is thinking";
	time = get_time_in_ms() - philo->data->time;
	if (msg == 2)
	{
		pthread_mutex_lock(&philo->m_eat);
		philo->last_eat = get_time_in_ms();
	}
	pthread_mutex_lock(&philo->data->m_print);
	if (g_is_philo_dead)
		return ;
	printf("%.6llu Philo %.3d : %s\n", time, philo->ph_id + 1, message);
	pthread_mutex_unlock(&philo->data->m_print);
}
