/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:03 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/02 17:55:58 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_data(t_data *data)
{
	if (data->nb < 1)
		return (ft_print("Error : there is no philosopher here!\n", 1));
	else if (data->nb == 1)
	{
		ft_print_one(data); // faire une routine speciale one
		return (1);
	}
	else if (data->die / 1000 < 0 || data->eat / 1000 < 0
		|| data->sleep / 1000 < 0 || data->must_eat < 0)
		return (ft_print("Error : wrong parameters\n", 1));
	return (0);
}

int	ft_check_arg(int ac, char **av, t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!(av[i][j] >= '0' && av[i][j] <= '9'))
				return (ft_print("Error in arguments\n", 1));
			j++;
		}
		i++;
	}
	if (ft_check_data(data) == 1)
		return (1);
	return (0);
}

int	ft_check_count(t_data *data)
{
	pthread_mutex_lock(data->philo->m_count);
	if (data->philo->count == data->must_eat && data->life == 0)
	{
		pthread_mutex_unlock(data->philo->m_count);
		return (1);
	}
	pthread_mutex_unlock(data->philo->m_count);
	return (0);
}
/*
void	*ft_routine_one(void *one)
{
	t_philo	*one_cp;
	t_data	*data;

	one_cp = (t_philo *)one;
	data = one_cp->data;
	printf("0 philo 1 has taken a fork\n");
	usleep(data->die);
	printf("%d philo 1 is dead\n", data->die);
	return (NULL);
}
*/