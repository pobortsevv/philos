/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:18:21 by sabra             #+#    #+#             */
/*   Updated: 2021/05/02 15:33:49 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define DEAD 0

typedef struct	s_ph
{
	size_t		number;
	pthread_t	thread;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		n_time_must_eat;
	size_t		number_of_philos;
	size_t		time_to_die_reserv;
	pthread_mutex_t *forks;
}		t_ph;

int	ft_atoi(const char *str);
t_ph	*init_args(int ac, char **av);

#endif
