/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astridgaultier <astridgaultier@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 15:41:11 by asgaulti          #+#    #+#             */
/*   Updated: 2021/12/03 17:45:54 by astridgault      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char**av)
{
	t_data	data;
	int		ret;

	if (!(ac == 5 || ac == 6))
		return (ft_print("Error : wrong number of arguments\n", 1));
	ret = ft_init_data(&data, av, ac);
	if (ret > 0)
	{
		if (ret == 2)
			return (ft_simple_exit(&data));
		else
			ft_exit(&data);
		return (1);
	}
	ft_exit(&data);
	return (0);
}
