/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:19 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/02 16:22:14 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
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

void	ft_print_one(t_data *data)
{
	printf("0 philo 1 has taken a fork\n");
	printf("%d ", data->die / 1000);
	printf("philo 1 is dead\n");
}
