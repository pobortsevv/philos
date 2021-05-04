/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:14:05 by sabra             #+#    #+#             */
/*   Updated: 2021/05/04 19:33:39 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

size_t	ft_strlen(const char *str)
{ 
	return ((sizeof(str)) / sizeof(char) - 1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
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
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void			ft_usleep(int time)
{
	unsigned long end;

	end = time_now() + time;
	while (time_now() < end) // Или пока не сдохнут
		usleep(time);
}

int	ph_print(char *str, int number)
{
	int count;

	pthread_mutex_lock(&g_all.print);
	count = printf("%lu %d %s\n", (time_now() - g_all.start), number,
			str);
	pthread_mutex_unlock(&g_all.print);
	return (count);
}

int	init_args(int ac, char **av)
{
	g_all.n_of_philos = ft_atoi(av[1]);
	g_all.t_to_die = ft_atoi(av[2]);
	g_all.t_to_eat = ft_atoi(av[3]);
	g_all.t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		g_all.nt_must_eat = ft_atoi(av[5]);
	else
		g_all.nt_must_eat = -1;
	g_all.philos = (t_ph *)malloc(sizeof(t_ph) * g_all.n_of_philos + 1);
	if (!g_all.philos)
		return (1);
	if (g_all.n_of_philos < 2 || g_all.t_to_die < 0
			|| g_all.t_to_eat < 0 || g_all.t_to_sleep < 0
			|| (ac  == 6 && g_all.nt_must_eat < 0))
	{
		free(g_all.philos);
		return (1);
	}
	pthread_mutex_init(&g_all.print, NULL);
	pthread_mutex_init(&g_all.death, NULL);
	return (0);
}
