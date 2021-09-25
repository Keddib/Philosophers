/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:37:05 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 16:14:55 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher(void *arg)
{
	// take a fork
	// start earting; > when finish unlock fork;
	// sleep ;
	// then think;


	// ?? who can I know the philosopher number here.

}


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

	//create n of philos required
	//create n of ph_satatus required;


	while (i < data.n_philo)
	{
		// init philo_id with i;
		//init ph_status->data with data adress;
		pthread_create(&philo[i], NULL, philosopher, ph_status[i]);
		i++;
	}

	//check philos status
	return (0);
}
