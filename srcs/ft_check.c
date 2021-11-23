/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:28:03 by asgaulti          #+#    #+#             */
/*   Updated: 2021/11/23 22:10:17 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_data(t_data *data)
{
	if (data->nb < 1)
	{
		ft_print("Error : there is no philosopher here!\n");
		return (1);
	}
	else if (data->nb == 1)
	{
		ft_print_one(data);
		//ft_join_thread(data);
		// faire mourir le philo (apres qu'il ait pris une fork?) en envoyant le msge philo dies
		// free si necessaire ?
		return (1);
	}
	else if (data->nb > 200)
	{
		ft_print("Error : there are too many philosophers here!\n");
		return (1);
	}
	else if (data->die / 1000 < 60 || data->eat / 1000 < 60
		|| data->sleep / 1000 < 60 || data->must_eat < 0)
	{
		ft_print("Error : wrong parameters\n");
		return (1);
	}
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
			{
				ft_print("Error in arguments\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	if (ft_check_data(data) == 1)
		return (1);
	return (0);
}
