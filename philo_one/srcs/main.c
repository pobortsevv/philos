/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 16:48:28 by sabra             #+#    #+#             */
/*   Updated: 2021/05/03 11:01:02 by sabra            ###   ########.fr       */
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

//void	*ph_status(void *arg)
//{
	//t_ph *philo;
//
	//philo = (t_ph *)arg;
	//while (ph_life(philo))
		//;
	//return ((void *)DEAD);
//}
//
//void	ph_start(t_ph *philos, pthread_mutex_t *ar_forks)
//{
	//size_t	len;
	//size_t	i;
	//int	err;
//	
	//len = philos[0].number_of_philos;
	//i = 0;
	//while (i < len)
	//{
		//philos[i].forks = ar_forks;
		//err = pthread_create(&philos[i].thread, NULL, ph_status, &philos[i]);
		//if (err != 0)
		//{
			//write(STDERR, "Невозможно создать поток\n", 24); 
			//return ;
		//}
		//err = pthread_detach(philos[i].thread);
		//if (err != 0)
		//{
			//write(STDERR, "Невозможно присоединить поток\n", 29); 
			//return ;
		//}
		//i++;
	//}
//}

int	main(int ac, char **av)
{
	t_ph		*philos;
	pthread_mutex_t	*forks;
	size_t		i;

	if (ac < 5 || ac > 6)
		return (write(STDERR, "Wrong number of arguments\n", 26) - 25);
	//philos = init_args(ac, av);
	//if (!philos)
		//return (write(STDERR, "Wrong arguments\n", 16) - 15);
	//forks = (pthread_mutex_t *)malloc(sizeof(pthread_t) * philos[0].number_of_philos);
	//i = 0;
	//while (i < philos[0].number_of_philos)
	//{
		////TODO Сделать защиту для инициализации
		//pthread_mutex_init(&forks[i], NULL);
		//i++;
	//}
	//ph_start(philos, forks);
	return (0);
}
