/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:19 by asgaulti          #+#    #+#             */
/*   Updated: 2021/11/23 22:11:06 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_print_action(t_philo *philo, t_data *data, char *str)
{
	// printf("address = %p\n", data);
	pthread_mutex_lock(data->write);
	pthread_mutex_lock(data->dead);
	if (data->life == 0)
	{
		pthread_mutex_unlock(data->dead);
		data->time = ft_gettime(&data->start_time);
		printf("%ld ", data->time / 1000);
		printf("philo %d %s\n", philo->philo_nb, str);
		pthread_mutex_unlock(data->write);
	}
	else
	{
		data->time = ft_gettime(&data->start_time);
	printf("%ld ", data->time / 1000);
	printf("philo %d %s\n", philo->philo_nb, str);
	//pthread_mutex_unlock(data->dead);
	pthread_mutex_unlock(data->write);
	}
}

void	ft_print_one(t_data *data)
{
	printf("%d ", data->die / 1000);
	printf("philo 1 is dead\n");
}