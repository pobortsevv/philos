/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:18:21 by sabra             #+#    #+#             */
/*   Updated: 2021/05/04 19:30:53 by sabra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
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
	int		eat_count;
	int		t_to_die;
	int		die_time_reserv;
	unsigned long	wait_time;
}		t_ph;

typedef struct	s_all
{
	int		t_to_die;
	int		t_to_eat;
	int		t_to_sleep;
	int		n_of_philos;
	int		nt_must_eat;
	unsigned long	start;
	pthread_mutex_t *forks;
	pthread_mutex_t	print;
	pthread_mutex_t death;
	t_ph		*philos;
}		t_all;

extern	t_all	g_all;

int	ft_atoi(const char *str);
int	init_args(int ac, char **av);
unsigned long	time_now(void);
int	ph_print(char *str, int number);
void	ft_usleep(int time);

#endif
