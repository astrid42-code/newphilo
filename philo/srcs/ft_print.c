/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:19 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/03 19:14:08 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print(char *str, int ret)
{
	write(1, str, ft_strlen(str));
	return (ret);
}

void	ft_print_action(t_philo *philo, t_data *data, char *str)
{
	pthread_mutex_lock(data->write);
	pthread_mutex_lock(data->dead);
	if (data->life == 0)
	{
		pthread_mutex_unlock(data->dead);
		pthread_mutex_lock(data->m_time);
		data->time = ft_gettime(&data->start_time);
		printf("%ld ", data->time / 1000);
		pthread_mutex_unlock(data->m_time);
		printf("philo %d %s\n", philo->philo_nb, str);
		pthread_mutex_unlock(data->write);
	}
	else
	{
		pthread_mutex_unlock(data->dead);
		pthread_mutex_lock(data->m_time);
		data->time = ft_gettime(&data->start_time);
		printf("%ld ", data->time / 1000);
		pthread_mutex_unlock(data->m_time);
		printf("philo %d %s\n", philo->philo_nb, str);
		pthread_mutex_unlock(data->write);
	}
}
