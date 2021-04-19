/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:48:28 by sabra             #+#    #+#             */
/*   Updated: 2021/04/18 18:30:38 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

int	init_args(t_opt *opts, char **av)
{
	int argument;

	argument = ft_atoi(av[0]);
	if (argument < 0)
		return (0);
	opts->number_of_philos = argument;
	return (1);
	
}

int	main(int ac, char **av)
{
	t_opt opts;

	(void)ac;
	//if (ac < 4)
		//return (0);
	init_args(&opts, av);
	return (0);
}
