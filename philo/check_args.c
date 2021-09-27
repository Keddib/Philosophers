/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keddib <keddib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 11:58:36 by keddib            #+#    #+#             */
/*   Updated: 2021/09/27 10:24:14 by keddib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

int	ft_atoi(char *str)
{
	int	i;
	int	p;
	int	r;

	i = 0;
	p = 1;
	r = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			p = -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (r * p);
}

int	is_digit(char *s)
{
	while (*s)
	{
		if (*s < 48 || *s > 57)
			return (0);
		s++;
	}
	return (1);
}

int	is_args_digit(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (!is_digit(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(char **args, int n, t_data *data)
{
	int	last_arg;

	if ((n != 5 && n != 6) || !is_args_digit(args))
		return (printf("ARGS ERROR\n"));
	g_is_philo_dead = 0;
	data->time = get_time_in_ms();
	data->n_philo = ft_atoi(args[0]);
	data->time_die = ft_atoi(args[1]);
	data->time_eat = ft_atoi(args[2]);
	data->time_sleep = ft_atoi(args[3]);
	if (n == 6)
	{
		data->n_time_must_eat = ft_atoi(args[4]);
		last_arg = 1;
	}
	else
		last_arg = 0;
	if (last_arg && (data->n_time_must_eat == 0))
		return (1);
	n = 0;
	data->forks = malloc(data->n_philo * sizeof(pthread_mutex_t));
	pthread_mutex_init(&data->m_print, NULL);
	while (n < data->n_philo)
		pthread_mutex_init(&data->forks[n++], NULL);
	return (0);
}
