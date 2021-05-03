/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:48:28 by sabra             #+#    #+#             */
/*   Updated: 2021/05/03 13:08:15 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_all	g_all;

//int	ph_life(t_ph *philo)
//{
	//if (philo->time_to_die && philo->time_to_eat < philo->time_to_die)
	//{
		//forks_lock(philo);
		//printf("%zu has taken a fork\n", philo->number);
		//printf("%zu has taken a fork\n", philo->number);
		//printf("%zu is eating\n", philo->number);
		//usleep(philo->time_to_eat * 1000);
		//forks_unlock(philo);
		////philo->time_to_die = philo->time_to_die_reserv;
		//printf("%zu is sleeping\n", philo->number);
		//usleep(philo->time_to_sleep * 1000);
		//printf("%zu is thinking\n", philo->number);
		//usleep(philo->time_to_sleep * 1000);
		//philo->time_to_die -= philo->time_to_sleep;
	//}
	//else
		//return (printf("%zu philosopher is dead\n", philo->number) * 0);
	//return (1);
//}

void	*ph_routine(void *arg)
{
	t_ph *philo;

	philo = (t_ph *)arg;
	//while (ph_life(philo))
		//;
	return ((void *)DEAD);
}

void	ph_start(int i, int j, int k)
{
	while (++i < g_all.n_of_philos)
	{
		g_all.philos[i].number = i + 1;
		g_all.philos[i].right = (i + 1) % g_all.n_of_philos;
		g_all.philos[i].left = i;
		g_all.philos[i].eat_count = 0;
	}
	while (++j < g_all.n_of_philos)
	{
		if (pthread_create(&g_all.philos[i].thread, NULL, ph_routine,
					(void *)(&g_all.philos[i])) != 0)
			return ;
	}
	while (++k < g_all.n_of_philos)
		pthread_join(g_all.philos[i].thread, NULL);
}

int	main(int ac, char **av)
{
	int		i;

	if (ac < 5 || ac > 6 || init_args(ac, av))
		return (write(STDERR, "Wrong arguments\n", 16) - 15);
	g_all.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * g_all.n_of_philos);
	i = 0;
	while (i < g_all.n_of_philos)
	{
		if (pthread_mutex_init(&g_all.forks[i], NULL) != 0)
		{
			free(g_all.forks);
			return (write(STDERR, "Error with malloc\n", 17) - 16);
		}
		i++;
	}
	g_all.start = time_now();
	ph_start(-1, -1, -1);
	return (0);
}
