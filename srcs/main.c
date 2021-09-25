/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:41:11 by asgaulti          #+#    #+#             */
/*   Updated: 2021/09/22 18:46:44 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char**av)
{
	t_data	data;

	if (!(ac == 5 || ac == 6))
	{
		ft_print("Error : wrong number of arguments\n");
		return (1);
	}
	if (ft_init_data(&data, av, ac) == 1)
	{
		ft_exit(&data);
		//ft_free(&data); // ou ft_exit?
		return (1);
	}
	ft_exit(&data);
	return (0);
}
