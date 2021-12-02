/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:08:04 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/02 17:10:31 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *philo)
{
	int		i;
	t_philo	*philo_cp;
	t_data	*data;

	i = 0;
	philo_cp = (t_philo *)philo;
	data = philo_cp->data;
	pthread_mutex_lock(data->synchro);
	pthread_mutex_unlock(data->synchro);
	if (philo_cp->philo_nb % 2 == 0)
	{
		//printf("paf = %d\n", philo_cp->philo_nb);
		usleep(1000);
	}
		//printf("pouf = %d\n", philo_cp->philo_nb);
	
	//pthread_mutex_lock(data->dead);
	//while (data->life == 0)
	while (ft_check_end(data) == 0)
	{
	//	pthread_mutex_unlock(data->dead);
		if (ft_launch_philo(philo_cp, data) == 1)
		{
			break ;
		}
		if (data->must_eat != 0)
		{
			pthread_mutex_lock(philo_cp->m_count);
			if (philo_cp->count == data->must_eat)
			{
				pthread_mutex_unlock(philo_cp->m_count);
				break ;
			}
			philo_cp->count++;
			//printf("c= %d\n", philo_cp->count);
			pthread_mutex_unlock(philo_cp->m_count);
		}
	}
	return (NULL);
}

int	ft_launch_philo(t_philo *philo, t_data *data)
{
	if (ft_check_end(data) == 1)
		return (1);
	if (ft_time_to_eat(philo, data) == 1)
	{
		return (1);
	}
	if (ft_check_end(data) == 1)
		return (1);
	ft_usleep(data->sleep);
	if (ft_check_end(data) == 1)
		return (1);
	ft_print_action(philo, data, "is sleeping");
	if (ft_check_end(data) == 1)
		return (1);
	ft_print_action(philo, data, "is thinking");
	return (0);
}

int	ft_time_to_eat(t_philo *philo, t_data *data)
{
	if (ft_take_fork(philo, data) == 1)
		return (1);
	pthread_mutex_lock(philo->m_last_eat);
	philo->last_eat = ft_gettime(&data->start_time);
	pthread_mutex_unlock(philo->m_last_eat);
	if (ft_check_end(data) == 1)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}
	ft_print_action(philo, data, "is eating");
	ft_usleep(data->eat);
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	return (0);
}

int	ft_take_fork(t_philo *philo, t_data *data)
{
	//printf("l %p r %p\n", philo->left_f, philo->right_f);
	pthread_mutex_lock(philo->left_f);
	pthread_mutex_lock(philo->right_f);
	if (ft_check_end(data) == 1)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}
	ft_print_action(philo, data, "has taken a (left) fork");
	if (ft_check_end(data) == 1)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}	
	ft_print_action(philo, data, "has taken a (right) fork");
	return (0);
}

int	ft_reach_count(t_data *data)
{
	ft_join_thread(data);
	ft_print("count reached\n");
	ft_exit(data);
	return (1);
}