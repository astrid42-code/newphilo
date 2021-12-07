/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:51:59 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/04 12:45:24 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_gettime(t_timeval *start_time)
{
	t_timeval		current;
	unsigned long	time;

	gettimeofday(&current, NULL);
	time = (((current.tv_sec - start_time->tv_sec) * 1000000)
			+ (current.tv_usec - start_time->tv_usec));
	return (time);
}

unsigned long	ft_gettime_lasteat(int i, t_data *data)
{
	long int		time;
	unsigned long	res;

	pthread_mutex_lock(data->philo[i].m_last_eat);
	time = ft_gettime(&data->start_time);
	res = time - data->philo[i].last_eat;
	if (res > (unsigned long)data->die)
	{
		pthread_mutex_unlock(data->philo[i].m_last_eat);
		return (1);
	}
	pthread_mutex_unlock(data->philo[i].m_last_eat);
	return (0);
}
