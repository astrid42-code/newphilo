/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:07 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/04 12:28:11 by asgaulti         ###   ########.fr       */
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
		usleep(50);
}

int	ft_check_count_rout(t_philo *philo_cp, t_data *data)
{
	(void)data;
	pthread_mutex_lock(philo_cp->m_count);
	philo_cp->count++;
	if (philo_cp->count == data->must_eat - 1)
	{
		pthread_mutex_unlock(philo_cp->m_count);
		return (1);
	}
	pthread_mutex_unlock(philo_cp->m_count);
	return (0);
}

void	ft_special(t_data *data)
{
	if (data->nb % 2 != 0)
	{
		if (2 * data->eat - data->sleep > 0)
			ft_usleep(2 * data->eat - data->sleep);
	}
}
