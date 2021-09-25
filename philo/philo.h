/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:46:35 by keddib            #+#    #+#             */
/*   Updated: 2021/09/25 16:06:55 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>

typedef struct	s_philo
{
	uint64_t	last_eat;
	int			n_time_eats;
	int			ph_id;
	t_data		*data;

}				t_philo;

typedef struct	s_data
{
	int	n_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	notepme;
	int	last_arg;
	pthread_mutex_t	*forks;
}				t_data;

int	check_args(char **args, int n, t_data *data);

#endif
