/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:48:28 by sabra             #+#    #+#             */
/*   Updated: 2021/05/15 17:00:00 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_all	g_all;

int	ph_life(t_ph *philo)
{
	sem_wait(g_all.forks);
	ph_print("has taken a fork", philo->number, 1);
	sem_wait(g_all.forks);
	ph_print("has taken a fork", philo->number, 1);
	ph_print("is eating", philo->number, 1);
	philo->wait_time = time_now();
	usleep(g_all.t_to_eat * 1000);
	philo->eat_count++;
	if (philo->eat_count == g_all.nt_must_eat)
		ph_print("\033[0;31m\033[1mdied \033[0m", philo->number, 0);
	sem_post(g_all.forks);
	sem_post(g_all.forks);
	ph_print("is sleeping", philo->number, 1);
	usleep(g_all.t_to_sleep * 1000);
	ph_print("is thinking", philo->number, 1);
	return (1);
}

void	*ph_checker(void *arg)
{
	t_ph *philo;

	philo = (t_ph *)arg;
	usleep(5);
	while (1)
	{
		usleep(1000);
		if ((unsigned long)g_all.t_to_die < (time_now() - philo->wait_time))
		{
			ph_print("\033[0;31m\033[1mdied \033[0m", philo->number, 0);
		}
	}
	return (arg);
}

void	ph_routine(t_ph *philo)
{
	if (philo->number % 2 == 0)
		usleep(1000);
	philo->wait_time = time_now();
	if (pthread_create(&philo->checker, NULL, ph_checker, philo) != 0)
		return ;
	pthread_detach(philo->checker);
	while (ph_life(philo))
		;
}

void	ph_start(int i)
{
	int status;

	while (++i < g_all.n_of_philos)
	{
		g_all.philos[i].number = i + 1;
		g_all.philos[i].eat_count = 0;
		g_all.philos[i].t_to_die = g_all.t_to_die;
	}
	i = -1;
	g_all.start = time_now();
	while (++i < g_all.n_of_philos)
	{
		g_all.philos[i].pid = fork(); 
		if (g_all.philos[i].pid == 0)
			ph_routine(&g_all.philos[i]);
	}
	while (1)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status))
			break ;
	}
}

int	main(int ac, char **av)
{
	int i;

	i = 0;
	if (ac < 5 || ac > 6 || init_args(ac, av))
		return (write(STDERR, "Wrong arguments\n", 16) - 15);
	g_all.forks = sem_open("forks", O_CREAT|O_EXCL, S_IRWXU,
			g_all.n_of_philos);
	if (g_all.forks == SEM_FAILED)
		return (write(STDERR, "Error with semaphor\n", 20) - 19);
	ph_start(-1);
	sem_unlink("print");
	sem_unlink("forks");
	while (i < g_all.n_of_philos && g_all.philos[i].pid != 0)
	{
		kill(g_all.philos[i].pid, SIGKILL);
		i++;
	}
	free(g_all.philos);
	return (0);
}
