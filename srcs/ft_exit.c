/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:27:50 by asgaulti          #+#    #+#             */
/*   Updated: 2021/11/23 15:53:03 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)data->philo;
	//puts("che");
	//ft_join_thread(data);
	// if (data->life == 1)
	// 	pthread_mutex_unlock(data->dead);
	// if (data->must_eat != 0 && data->life == 0)
	// 	ft_print("count reached\n");
	while (i < data->nb)
	{
		//puts("che");
		pthread_mutex_destroy(data->philo[i].left_f);
		i++;
	}
	pthread_mutex_destroy(data->write);
	// if (data->life == 1)
	// 	pthread_mutex_unlock(data->dead);
	//puts("che");
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

int	ft_simple_exit(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)data->philo;
	//free(data);
	return (1);
}

int	ft_check_end(t_data *data)
{
	pthread_mutex_lock(data->dead);
	if (data->life == 1)
	{
	//printf("life2 = %d\n", data->life);
		pthread_mutex_unlock(data->dead);
		return (1);
	}
	pthread_mutex_unlock(data->dead);
	return (0);
}
