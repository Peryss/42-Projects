/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:49:59 by pvass             #+#    #+#             */
/*   Updated: 2025/01/15 18:21:49 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*run;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	*run_lock;
	pthread_mutex_t	*start_lock;
}	t_philo;

typedef struct s_program
{
	int				run_flag;
	int				start_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	run_lock;
	pthread_mutex_t	start_lock;
	t_philo			*philos;
}	t_program;

void	*ft_calloc(size_t nitems, size_t size);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
size_t	get_time(void);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

/*input*/
int		invalid_args(char **argv);
int		wrong_input(char *str);

void	init_program(t_program *program, t_philo *philos,
			pthread_mutex_t *forks);
void	init_forks(t_program *program, pthread_mutex_t *forks, char **argv);
void	init_philosophers(t_program *program, t_philo *philos,
			pthread_mutex_t *forks, char **argv);

void	print_msg(char *msg, t_philo *philos);
void	create_and_destroy_threads(t_program *program, pthread_mutex_t *forks);
void	*routine(void *content);
void	check_safe_exit_thread(t_philo *philo);
int		run_and_not_dead(t_philo *philo);
void	p_sleep_nomsg(size_t time, t_philo *philo);
void	set_to_finished(t_program *program);
void	*observe(void *pointer);
int		finished(t_program *program);
int		is_dead(t_philo *philos);
int		all_ate_enough(t_philo *philos);
void	safe_exit(char *str, t_program *program,
			pthread_mutex_t *forks, int error);
void	print_philo(t_philo *p);
void	print_died(t_philo *philos);

#endif
