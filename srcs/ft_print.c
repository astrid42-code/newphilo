/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:19 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/25 16:04:11 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_print_action(t_philo *philo, t_data *data, char *str)
{
	(void)data;
	pthread_mutex_lock(data->write);
	data->time = ft_gettime(&data->start_time);
	printf("%ld ", data->time / 1000); // / 1000
	printf("philo %d %s\n", philo->philo_nb, str);
	pthread_mutex_unlock(data->write);
}
