/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:14:05 by sabra             #+#    #+#             */
/*   Updated: 2021/05/15 16:32:37 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] != '\0')
		return (-1);
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if (result > 2147483647)
			return (-1);
		else if (result < -2147483648)
			return (0);
	}
	return (result);
}

unsigned long	time_now(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ph_print(char *str, int number, int status)
{
	sem_wait(g_all.print);
	printf("%lu %d %s\n", (time_now() - g_all.start), number,
			str);
	if (status == 0)
		exit(1);
	sem_post(g_all.print);
	return (0);
}

int	init_args(int ac, char **av)
{
	sem_unlink("print");
	sem_unlink("forks");
	g_all.n_of_philos = ft_atoi(av[1]);
	g_all.t_to_die = ft_atoi(av[2]);
	g_all.t_to_eat = ft_atoi(av[3]);
	g_all.t_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		g_all.nt_must_eat = ft_atoi(av[5]);
	else
		g_all.nt_must_eat = -1;
	g_all.philos = (t_ph *)malloc(sizeof(t_ph) * g_all.n_of_philos);
	if (g_all.philos == NULL)
		return (1);
	if (g_all.n_of_philos < 2 || g_all.t_to_die < 0
		|| g_all.t_to_eat < 0 || g_all.t_to_sleep < 0
		|| (ac == 6 && g_all.nt_must_eat < 0))
	{
		free(g_all.philos);
		return (1);
	}
	g_all.print = sem_open("print", O_CREAT|O_EXCL, S_IRWXU, 1);
	return (0);
}
