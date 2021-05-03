/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabra <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 18:18:21 by sabra             #+#    #+#             */
/*   Updated: 2021/05/03 10:58:03 by sabra            ###   ########.fr       */
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

typedef struct	s_all
{
	size_t		t_to_die;
	size_t		t_to_eat;
	size_t		t_to_sleep;
	size_t		n_of_philos;
	pthread_mutex_t *forks;

}		t_all;

typedef struct	s_ph
{
	size_t		number;
	pthread_t	thread;
	int		right;
	int		left;
}		t_ph;

int	ft_atoi(const char *str);
t_ph	*init_args(int ac, char **av);

#endif
