/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:37:05 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 18:47:26 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char *argv[])
{
	int			i;
	t_data		data;
	pthread_t	*philo;
	t_philo		*ph_status;

	i = 0;
	if (check_args(++argv, argc, &data))
		return (1);
	else if (data.last_arg && data.notepme == 0)
		return (0);
	philo = (pthread_t *)malloc(data.n_philo * sizeof(pthread_t));
	ph_status = (t_philo *)malloc(data.n_philo * sizeof(t_philo));
	while (i < data.n_philo)
	{
		// init philo_id with i;
		ph_status[i].ph_id = i;
		ph_status[i].n_time_eats = 0;
		//init ph_status->data with data adress;
		ph_status[i].data = &data;
		pthread_create(&philo[i], NULL, philosopher, (void *)&ph_status[i]);
		i++;
	}
	while (1)
	{
		// for (int i = 0; i < data.n_philo; i++)
		// {
		// 	if ((get_time_in_ms() - ph_status[i].last_eat) > (unsigned long long)data.time_die)
		// 	{
		// 		printf("%llu Philo %d : died\n", get_time_in_ms(), ph_status[i].ph_id + 1);
		// 		data.is_philo_dead = 1;
		// 	}
		// }
	}
	return (0);
}
