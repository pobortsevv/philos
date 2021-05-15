#ifndef PHILO_ONE_H
# define PHILO_ONE_H

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

typedef struct s_ph
{
	int				number;
	int				right;
	int				left;
	int				eat_count;
	int				die_time_reserv;
	pthread_t		thread;
	unsigned long	wait_time;
}			t_ph;

typedef struct s_all
{
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_of_philos;
	int				nt_must_eat;
	int				dead;
	unsigned long	start;
	pthread_t		checker;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	t_ph			*philos;
}		t_all;

extern t_all	g_all;

int					ft_atoi(const char *str);
int					init_args(int ac, char **av);
unsigned long		time_now(void);
int					ph_print(char *str, int number, int status);
void				ft_usleep(int time);
void				death_exit(void);

#endif
