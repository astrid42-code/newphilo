/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asgaulti <asgaulti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:41:11 by asgaulti          #+#    #+#             */
/*   Updated: 2021/11/22 15:23:39 by asgaulti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char**av)
{
	t_data	data;
	int		ret;

	if (!(ac == 5 || ac == 6))
	{
		ft_print("Error : wrong number of arguments\n");
		return (1);
	}
	ret = ft_init_data(&data, av, ac);
	if (ret > 0)
	{
		if (ret == 2)
			return (ft_simple_exit(&data));
		//ft_check_end(&data);
		else
		{
		puts("che2");
			ft_exit(&data);	
		}
		//ft_free(&data); // ou ft_exit?
		return (1);
	}
	ft_exit(&data);
	return (0);
}
