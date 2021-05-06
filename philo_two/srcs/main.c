/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:48:28 by sabra             #+#    #+#             */
/*   Updated: 2021/05/06 15:21:15 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_all	g_all;

int	ph_life(t_ph *philo)
{
	sem_wait(g_all.forks);
	sem_wait(g_all.forks);
	ph_print("has taken a fork", philo->number, 1);
	ph_print("has taken a fork", philo->number, 1);
	ph_print("is eating", philo->number, 1);
	philo->wait_time = time_now();
	philo->t_to_die = philo->die_time_reserv;
	usleep(g_all.t_to_eat * 1000);
	philo->eat_count++;
	sem_post(g_all.forks);
	sem_post(g_all.forks);
	philo->t_to_die -= (time_now() - philo->wait_time);
	if (philo->t_to_die < (int)(time_now() - philo->wait_time)
				|| philo->eat_count == g_all.nt_must_eat)
		return (ph_print("\033[0;31m\033[1mdied \033[0m", philo->number, 0) * 0);
	ph_print("is sleeping", philo->number, 1);
	philo->wait_time = time_now();
	usleep(g_all.t_to_sleep * 1000);
	philo->t_to_die -= (time_now() - philo->wait_time);
	if (philo->t_to_die < (int)(time_now() - philo->wait_time))
		return (ph_print("\033[0;31m\033[1mdied \033[0m", philo->number, 0) * 0);
	ph_print("is thinking", philo->number, 1);
	return (1);
}

void	*ph_routine(void *arg)
{
	size_t	i;

	i = (size_t)arg;
	g_all.start = time_now();
	g_all.philos[i].die_time_reserv = g_all.philos[i].t_to_die;
	g_all.philos[i].wait_time = time_now();
	if (g_all.philos[i].number % 2 == 0)
		usleep(5);
	while (ph_life(&g_all.philos[i]))
		;
	death_exit();
	return ((void *)DEAD);
}

void	ph_start(int i, int j, int k)
{
	while (++i < g_all.n_of_philos)
	{
		g_all.philos[i].number = i + 1;
		g_all.philos[i].eat_count = 0;
		g_all.philos[i].t_to_die = g_all.t_to_die;
	}
	while (++j < g_all.n_of_philos)
	{
		if (pthread_create(&g_all.philos[i].thread, NULL, ph_routine,
				(void *)(size_t)j) != 0)
			return ;
	}
	while (++k < g_all.n_of_philos)
		pthread_join(g_all.philos[i].thread, NULL);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6 || init_args(ac, av))
		return (write(STDERR, "Wrong arguments\n", 16) - 15);
	g_all.forks = sem_open("forks", O_CREAT|O_EXCL, S_IRWXU,
			g_all.n_of_philos);
	if (g_all.forks == SEM_FAILED)
		return (write(STDERR, "Error with semaphor\n", 20) - 19);
	ph_start(-1, -1, -1);
	return (0);
}