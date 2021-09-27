/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 17:51:59 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/26 17:52:37 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_gettime(t_timeval *start_time)
{
	t_timeval	current;
	unsigned long	time;

	gettimeofday(&current, NULL);
	time = (((current.tv_sec - start_time->tv_sec) * 1000000)
			+ (current.tv_usec - start_time->tv_usec));
	return (time);
}

unsigned long	ft_gettime_lasteat(unsigned long last_eat, t_data *data)
{
	long int	time;
	
	time = ft_gettime(&data->start_time);
	return (time - last_eat);
}
