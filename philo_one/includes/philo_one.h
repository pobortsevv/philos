/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:18:21 by sabra             #+#    #+#             */
/*   Updated: 2021/05/03 11:37:08 by sabra            ###   ########.fr       */
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
	int		number;
	pthread_t	thread;
	int		right;
	int		left;
}		t_ph;

typedef struct	s_all
{
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		n_of_philos;
	int		nt_must_eat;
	pthread_mutex_t *forks;
	pthread_mutex_t	print;
	pthread_mutex_t death;
	t_ph		*philos;
}		t_all;

extern	t_all	g_all;

int	ft_atoi(const char *str);
int	init_args(int ac, char **av);

#endif
