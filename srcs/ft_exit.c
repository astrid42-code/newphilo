/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:50 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/25 16:42:37 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)data->philo;
	ft_join_thread(data);
	if (data->must_eat != 0)
		ft_print("count reached\n");
	// else if (data->life == 1)
	// 	ft_print_action(philo, data, "died");
	while (i < data->nb)
	{
		pthread_mutex_destroy(data->philo[i].left_f);
		i++;
	}
	pthread_mutex_destroy(data->write);
	//ft_free(data, philo);
}

// a revoir (leaks et double free avec valgrind)
void	ft_free(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		free(philo);
		i++;
	}
	free(data);
}

void	ft_join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb)
	{
		 pthread_join(data->philo[i].philo_thread, NULL);
		 i++;
	}
}
/*
int	ft_check_death(t_philo *philo, t_data *data)
{
	if (data->time - data->start_time > data->die)
		life = 1;
}
*/
