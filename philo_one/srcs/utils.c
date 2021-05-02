/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:14:05 by sabra             #+#    #+#             */
/*   Updated: 2021/05/02 15:33:17 by sabra            ###   ########.fr       */
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

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void			ft_usleep(int time)
{
	unsigned long end;

	end = time_now() + time;
	while (time_now() < end) // Или пока не сдохнут
		usleep(time);
}

t_ph	*init_args(int ac, char **av)
{
	int	len;
	int	i;
	t_ph	*philos;

	len = ft_atoi(av[1]);
	if (len < 2)
		return (NULL);
	i = 0;
	philos = (t_ph *)malloc(sizeof(t_ph) * len + 1);
	if (!philos)
		return (NULL);
	while (i < len)
	{
		philos[i].number_of_philos = len;
		philos[i].number = i + 1;
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philos[i].n_time_must_eat = ft_atoi(av[5]);
		else
			philos[i].n_time_must_eat = -1;
		if (philos[i].time_to_die < 0 || philos[i].time_to_eat < 0
				|| philos[i].time_to_sleep < 0)
			return (NULL);
		i++;
	}
	return (philos);
}
