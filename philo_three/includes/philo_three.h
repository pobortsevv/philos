#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <unistd.h>
# define STDIN 0
# define STDOUT 1
# define STDERR 2
# define DEAD 0

typedef struct s_ph
{
	int				number;
	int				eat_count;
	int				t_to_die;
	int				die_time_reserv;
	unsigned long	wait_time;
	pid_t			pid;
	pthread_t		checker;
}		t_ph;

typedef struct s_all
{
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				n_of_philos;
	int				nt_must_eat;
	int				dead;	
	unsigned long	start;
	sem_t			*forks;
	sem_t			*print;
	t_ph			*philos;
}		t_all;

extern t_all	g_all;

int				ft_atoi(const char *str);
int				init_args(int ac, char **av);
unsigned long	time_now(void);
int				ph_print(char *str, int number, int status);
void			ft_usleep(int time);

#endif
