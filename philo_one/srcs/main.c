/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:48:28 by sabra             #+#    #+#             */
/*   Updated: 2021/05/10 12:40:19 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_all	g_all;

int	ph_life(t_ph *philo)
{
	pthread_mutex_lock(&g_all.forks[philo->right]);
	ph_print("has taken a fork", philo->number, 1);
	pthread_mutex_lock(&g_all.forks[philo->left]);
	ph_print("has taken a fork", philo->number, 1);
	philo->wait_time = time_now();
	ph_print("is eating", philo->number, 1);
	usleep(g_all.t_to_eat * 1000);
	pthread_mutex_unlock(&g_all.forks[philo->right]);
	pthread_mutex_unlock(&g_all.forks[philo->left]);
	philo->eat_count++;
	ph_print("is sleeping", philo->number, 1);
	//if (philo->t_to_die < (int)(time_now() - philo->wait_time) 
				//|| philo->eat_count == g_all.nt_must_eat)
		//return (ph_print("\033[0;31m\033[1mdied \033[0m", philo->number, 0) * 0);
	usleep(g_all.t_to_sleep * 1000);
	ph_print("is thinking", philo->number, 1);
	return (1);
}

void	*ph_checker(void *arg)
{
	t_ph	*philo;

	philo = (t_ph *)arg;
	while (1)
	{
		//usleep(1000);
		if (philo->t_to_die < (int)(time_now() - philo->wait_time) 
					|| philo->eat_count == g_all.nt_must_eat)
			ph_print("\033[0;31m\033[1mdied \033[0m", philo->number, 0);
	}
	return ((void *)0);
}

void	*ph_routine(void *arg)
{
	t_ph	*philo;

	philo = (t_ph *)arg;
	g_all.start = time_now();
	philo->wait_time = time_now();
	if (pthread_create(&philo->checker, NULL, ph_checker,
			(void *)(philo)) != 0)
		return ((void *)0);
	pthread_detach(philo->checker);
	//if (philo->number % 2 == 0)
		//usleep(10);
	while (ph_life(philo))
		;
	return ((void *)DEAD);
}

void	ph_start(int i, int j, int k)
{
	while (++i < g_all.n_of_philos)
	{
		g_all.philos[i].number = i + 1;
		g_all.philos[i].left = i;
		g_all.philos[i].right = (i + 1) % g_all.n_of_philos;
		g_all.philos[i].eat_count = 0;
		g_all.philos[i].t_to_die = g_all.t_to_die;
	}
	while (++j < g_all.n_of_philos)
	{
		if (g_all.philos[j].number % 2 == 0)
			usleep((g_all.t_to_eat * 0.5));
		if (pthread_create(&g_all.philos[j].thread, NULL, ph_routine,
				(void *)(&g_all.philos[j])) != 0)
			return ;
	}
	while (++k < g_all.n_of_philos)
		pthread_join(g_all.philos[k].thread, NULL);
}

int	main(int ac, char **av)
{
	int		i;

	if (ac < 5 || ac > 6 || init_args(ac, av))
		return (write(STDERR, "Wrong arguments\n", 16) - 15);
	g_all.forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* g_all.n_of_philos);
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
	ph_start(-1, -1, -1);
	return (0);
}
