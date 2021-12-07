/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:08:04 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/07 10:47:40 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(t_philo *philo_cp)
{
	int		i;
	t_data	*data;

	i = 0;
	data = philo_cp->data;
	pthread_mutex_lock(data->synchro);
	pthread_mutex_unlock(data->synchro);
	if (data->nb % 2 == 0 || data->nb == 1)
	{
		if (philo_cp->philo_nb % 2 == 0)
			ft_usleep(data->eat);
	}
	else
	{
		if (philo_cp->philo_nb % 3 == 1)
			ft_usleep(data->eat);
		if (philo_cp->philo_nb % 3 == 2)
			ft_usleep(2 * data->eat);
	}
	while (ft_check_end(data) == 0)
	{
		if (ft_launch_philo(philo_cp, data) == 1)
			break ;
	}
	return (NULL);
}

int	ft_launch_philo(t_philo *philo, t_data *data)
{
	if (ft_check_end(data) == 1)
		return (1);
	if (ft_time_to_eat(philo, data) == 1)
		return (1);
	if (ft_check_end(data) == 1)
		return (1);
	if (data->must_eat > 0)
	{
		if (ft_check_count_rout(philo, data) == 1)
			return (1);
	}
	if (ft_check_end(data) == 1)
		return (1);
	ft_print_action(philo, data, "is sleeping");
	if (ft_check_end(data) == 1)
		return (1);
	ft_usleep(data->sleep);
	ft_special(data);
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
	if (philo->philo_nb == data->nb)
	{
		if (ft_special_one(data, philo))
			return (1);
	}
	else
	{
		pthread_mutex_lock(philo->left_f);
		pthread_mutex_lock(philo->right_f);
	}
	if (ft_check_end(data) == 1)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}
	ft_print_action(philo, data, "has taken a fork");
	if (ft_check_end(data) == 1)
	{
		pthread_mutex_unlock(philo->left_f);
		pthread_mutex_unlock(philo->right_f);
		return (1);
	}	
	ft_print_action(philo, data, "has taken a fork");
	return (0);
}

int	ft_special_one(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(philo->right_f);
	if (data->nb == 1)
		ft_print_action(philo, data, "has taken a fork");
	while (data->nb == 1)
	{
		if (ft_check_end(data))
		{
			pthread_mutex_unlock(philo->right_f);
			return (1);
		}
	}
	pthread_mutex_lock(philo->left_f);
	return (0);
}

//pour démarrer la routine en cas de nombre impair :

// if (index % 3 == 0)
// 	pas sleep
// if (index % 3 == 1)
// 	sleep time to eat
// if (index % 3 == 2)
// 	sleep 2 time to eat

// apres manger
// attendre 2 tteat - 1 ttsleep

//exemple :
// 3 610 200 200

// 0	1 mange
// 200	1 dort
// 200 2 mange
// 400 1 pense
// 400 2 dort
// 400 3 mange
// 600 1 mange
// 600	2 pense