/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/15 17:46:35 by keddib            #+#    #+#             */
/*   Updated: 2021/09/27 12:16:40 by keddib           ###   ########.fr       */
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

typedef struct s_data
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_time_must_eat;
	uint64_t		time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	m_print;
}				t_data;

typedef struct s_philo
{
	uint64_t		last_eat;
	int				n_time_eats;
	int				ph_id;
	pthread_mutex_t	m_eat;
	t_data			*data;
}				t_philo;

int			g_is_philo_dead;

int			check_args(char **args, int n, t_data *data);
void		*philosopher(void *arg);
uint64_t	get_time_in_ms(void);
void		ms_sleep(uint64_t time_eat);
void		print_philo_status(t_philo *philo, int msg);
int			supervisor(t_philo *philo, t_data data);

#endif
