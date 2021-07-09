# Philos
### Summary
In this project, I will learn the basics of threading a process. I will learn how to make threads. I will discover the mutex and semaphores of POSIX standard.
![enter image description here](https://upload.wikimedia.org/wikipedia/commons/7/7b/An_illustration_of_the_dining_philosophers_problem.png)
### Task

 - One or more philosophers are sitting at a round table doing one of three things: eating, thinking, or sleeping.
 - While eating, they are not thinking or sleeping, while sleeping, they are not eating or thinking and of course, while thinking, they are not eating or sleeping.
 - The philosophers sit at a circular table with a large bowl of spaghetti in the center
 - There are some forks on the table.
 - As spaghetti is difficult to serve and eat with a single fork, it is assumed that a philosopher must eat with two forks, one for each hand.
 - The philosophers must never be starving.
 - Every philosopher needs to eat.
 - Philosophers don’t speak with each other.
 - Philosophers don’t know when another philosopher is about to die.
 - Each time a philosopher has finished eating, he will drop his forks and start sleeping.
 - When a philosopher is done sleeping, he will start thinking.
 - The simulation stops when a philosopher dies.
 - Each program should have the same options: number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
	- number_of_philosophers: is the number of philosophers and also the number of forks
	- time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting his last meal or the beginning of the simulation, it dies
	- time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time he will need to keep the two forks.
	- time_to_sleep: is in milliseconds and is the time the philosopher will spend sleeping.
	- number_of_times_each_philosopher_must_eat: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.
- Each philosopher should be given a number from 1 to ’number_of_philosophers’. 	
-  Philosopher number 1 is next to philosopher number ’number_of_philosophers’. Any other philosopher with the number N is seated between philosopher N - 1 and philosopher N + 1 
-  Any change of status of a philosopher must be written as follows (with X replaced with the philosopher number and timestamp_in_ms the current timestamp in milliseconds) 
	-  timestamp_in_ms X has taken a fork 
	-  timestamp_in_ms X is eating 
	-  timestamp_in_ms X is sleeping 
	-  timestamp_in_ms X is thinking 
	-  timestamp_in_ms X died 
- The status printed should not be scrambled or intertwined with another philosopher’s status. 
-  You can’t have more than 10 ms between the death of a philosopher and when it will print its death. 
-  Again, philosophers should avoid dying!
### philo_one
1) One fork between each philosopher, therefore if they are multiple philosophers, there will be a fork at the right and the left of each philosopher.
2) To avoid philosophers duplicating forks, you should protect the forks state with a mutex for each of them.
3) Each philosopher should be a thread.
### philo_two
1) All the forks are in the middle of the table.
2)  They have no states in memory but the number of available forks is represented by a semaphore.
3)  Each philosopher should be a thread.
### philo_three
1) All the forks are in the middle of the table.
2) They have no states in memory but the number of available forks is represented by a semaphore.
3) Each philosopher should be a process and the main process should not be a philosopher.
## How to compile
	cd philo_<one/two/three>
	make
You will got an executable file which will get 4 arguments.
Example:

	./philo_one 4 310 200 100
![enter image description here](https://psv4.userapi.com/c536436/u482986620/docs/d10/e5fccbf628f3/Screen_Shot_2021-07-09_at_5_02_21_PM.png?extra=d6MulFuEwX1hcd_LTvUApIa6OzofL7rzV6jW1X2Ov9EehFUeuGAbIMmNc7eLk6ugXPYO-RcRjYwakzWX5p6LELVzuKY0b3SEIn0Z46UGFIbtcQWYB_YINuiT8QE4s8P4PaJ8eY8PPLSs_NPrQCIHDoGsG38) 



 
 
