/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:48:28 by sabra             #+#    #+#             */
/*   Updated: 2021/04/22 23:04:10 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void	*ph_thread(void *arg)
{
	write(STDOUT, "is sleeping\n", 12);
	(void)arg;
	return ((void *)1);
}

void	ph_start(t_opt *opts, pthread_t *philos, pthread_mutex_t *forks)
{
	size_t	len;
	size_t	i;
	int	err;
	void	*ret;
	
	len = opts->number_of_philos;
	i = 0;
	while (i < len)
	{
		err = pthread_create(&philos[i], NULL, ph_thread, NULL);
		if (err != 0)
		{
			write(STDERR, "Невозможно создать поток\n", 24); 
			return ;
		}
		err = pthread_join(philos[i], &ret);
		if (err != 0)
		{
			write(STDERR, "Невозможно присоединить поток\n", 29); 
			return ;
		}
		printf("Код выхода потока: %ld\nНомер потока: %ld\n", (long)ret, i + 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_ph		*philos;
	pthread_mutex_t	*forks;

	if (ac < 5 || ac > 6)
		return (write(STDERR, "Wrong number of arguments\n", 26) - 25);
	philos = init_args(ac, av);
	//TODO Сделать инициализацию вилок в виде правая и левая вилка
	//forks = (pthread_mutex_t *)malloc(sizeof(pthread_t) * opts.number_of_philos);
	//ph_start(&opts, philos, forks);
	return (0);
}
