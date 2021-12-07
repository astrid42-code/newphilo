/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:50 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/03 12:26:24 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_data *data)
{
	int		i;

	i = 0;
	free(data->write);
	free(data->m_time);
	free(data->dead);
	free(data->synchro);
	while (i < data->nb)
	{
		free(data->philo[i].m_last_eat);
		free(data->philo[i].left_f);
		free(data->philo[i].m_count);
		i++;
	}
	free(data->philo);
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

int	ft_simple_exit(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)data->philo;
	return (1);
}

int	ft_reach_count(t_data *data)
{
	ft_join_thread(data);
	ft_print("count reached\n", 1);
	return (1);
}
