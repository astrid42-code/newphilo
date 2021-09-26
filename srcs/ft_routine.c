/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:08:04 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/26 16:34:16 by asgaulti         ###   ########.fr       */
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
	if (philo_cp->philo_nb % 2 == 0)
		usleep(1000); //> mettre un mutex init plutot le usleep 
	// {
	// 	pthread_mutex_lock(data->m_init);
	// 	pthread_mutex_unlock(data->m_init);
	// }
	//while (1)
	while (data->life == 0 && data->must_eat != data->nb)
	{
		//printf("data->start = %ld %d\n", data->start_time.tv_sec, data->start_time.tv_usec);
		if (ft_launch_philo(philo_cp, data) == 1)
			break ;
		if (data->must_eat != 0)
		{
			//printf("c = %d\n", philo_cp->count);
			if (philo_cp->count == data->must_eat)
				break ;
			philo_cp->count++;
		}
	}
	return (NULL);
}

int	ft_launch_philo(t_philo *philo, t_data *data)
{
	//unsigned long	time;
	
	//gettimeofday(&philo->phi_time, NULL);
	//printf("phi_time = %ld %d\n", philo->phi_time.tv_sec, philo->phi_time.tv_usec);
	//data->time = ft_gettime(&data->start_time, &philo->phi_time);
	//printf("time = %ld\n", data->time);
	if (ft_check_end(data) == 1)
		return (1);
	ft_time_to_eat(philo, data);
	if (ft_check_end(data) == 1)
		return (1);
	ft_time_to_sleep(philo, data);
	if (ft_check_end(data) == 1)
		return (1);
	ft_time_to_think(philo, data);
	//philo->life = ft_check_death(philo, data); // a mettre ou???
	return (0);
}

void	*ft_time_to_eat(t_philo *philo, t_data *data)
{
	//gettimeofday(&philo->phi_time, NULL);
	//data->time = ft_gettime(&data->start_time, &philo->phi_time);
	//printf("time = %ld\n", data->time);
	pthread_mutex_lock(philo->left_f);
	ft_print_action(philo, data, "has taken a (left) fork");
	pthread_mutex_lock(philo->right_f);
	//data->time = ft_gettime(&data->start_time);
	ft_print_action(philo, data, "has taken a (right) fork");
	philo->last_eat = ft_gettime(&data->start_time);
	ft_usleep(data->eat);
	ft_print_action(philo, data, "is eating");
	pthread_mutex_unlock(philo->left_f);
	pthread_mutex_unlock(philo->right_f);
	return (NULL);
}

void	*ft_time_to_sleep(t_philo *philo, t_data *data)
{
	ft_usleep(data->sleep);
	ft_print_action(philo, data, "is sleeping");
	//usleep(100);
	return (NULL);
}

void	*ft_time_to_think(t_philo *philo, t_data *data)
{
	ft_print_action(philo, data, "is thinking");
	return (NULL);
}
