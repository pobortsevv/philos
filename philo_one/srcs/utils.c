/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:14:05 by sabra             #+#    #+#             */
/*   Updated: 2021/04/24 23:27:13 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlen(const char *str)
{
	return ((sizeof(str)) / sizeof(char) - 1);
}

static int	ft_space(char sym)
{
	if (sym == ' ' || (sym >= 9 && sym <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		else if (result < -2147483648 && sign == -1)
			return (0);
	}
	return (result * sign);
}

void	init_exit(t_ph *philos, char *err)
{
	//size_t i;
//
	//i = 0;
	(void)philos;
	write(STDERR, err, ft_strlen(err));
	//while (*philos != NULL)
	//{
		//free(&philos);
		//*philos = NULL;
		//philos++;
	//}
	exit(1);
}

t_ph	*init_args(int ac, char **av)
{
	int	argument;
	size_t	len;
	size_t	i;
	t_ph	*philos;

	argument = ft_atoi(av[1]);
	if (argument < 0)
		return (NULL);
	len = argument;
	i = 0;
	philos = (t_ph *)malloc(sizeof(t_ph) * len + 1);
	if (!philos)
		return (NULL);
	while (i < len)
	{
		philos[i].number_of_philos = len;
		philos[i].number = i + 1;
		argument = ft_atoi(av[2]);
		if (argument < 0)
			init_exit(philos, "Wrong second argument\n");
		philos[i].time_to_die = (size_t)argument;
		argument = ft_atoi(av[3]);
		if (argument < 0)
			init_exit(philos, "Wrong third argument\n");
		philos[i].time_to_eat = (size_t)argument;
		argument = ft_atoi(av[4]);
		if (argument < 0)
			init_exit(philos, "Wrong forth argument\n");
		philos[i].time_to_sleep = (size_t)argument;
		if (ac == 6)
		{
			argument = ft_atoi(av[5]);
			if (argument < 0)
				init_exit(philos, "Wrong fifth argument\n");
			philos[i].n_time_must_eat = (size_t)argument;
		}
		else
			philos[i].n_time_must_eat = -1;
		i++;
	}
	return (philos);
}
