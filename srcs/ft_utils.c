/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:07 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/25 16:20:21 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	ft_usleep(unsigned int wait)
{
	t_timeval	time;

	gettimeofday(&time, NULL);
	while (ft_gettime(&time) < wait)
		usleep(500);
}

int	ft_check_end(t_data *data)
{
	pthread_mutex_lock(data->dead);
	if (data->life == 1)
	{
		pthread_mutex_unlock(data->dead);
		return (1);
	}
	pthread_mutex_unlock(data->dead);
	return (0);
}
