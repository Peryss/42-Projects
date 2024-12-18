/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:15:04 by pvass             #+#    #+#             */
/*   Updated: 2024/12/12 13:37:45 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_program *program, pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (init_exit(program, forks, i, 0));
		i++;
	}
}

void	init_program(t_program *program, t_philo *philos)
{
	program->dead_flag = 0;
	program->run_flag = 1;
	program->start_flag = 0;
	program->philos = philos;
	if (pthread_mutex_init(&program->write_lock, NULL) != 0)
		return (write(2, "Mutex init error\n", 18), exit (4));
	if (pthread_mutex_init(&program->dead_lock, NULL) != 0)
		return (pthread_mutex_destroy(&program->write_lock),
			write (2, "Mutex init error\n", 18), exit (4));
	if (pthread_mutex_init(&program->run_lock, NULL) != 0)
		return (pthread_mutex_destroy(&program->dead_lock),
			pthread_mutex_destroy(&program->write_lock),
			write (2, "Mutex init error\n", 18), exit (4));
	if (pthread_mutex_init(&program->start_lock, NULL) != 0)
		return (pthread_mutex_destroy(&program->dead_lock),
			pthread_mutex_destroy(&program->write_lock),
			pthread_mutex_destroy(&program->run_lock),
			write (2, "Mutex init error\n", 18), exit (4));
}

void	input_to_philos(t_philo *philos, char **argv)
{
	philos->num_of_philos = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5] != NULL)
		philos->num_times_to_eat = ft_atoi(argv[5]);
	else
		philos->num_times_to_eat = -1;
}

void	init_philosophers(t_program *program, t_philo *philos,
		pthread_mutex_t *forks, char **argv)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philos[i].id = i;
		input_to_philos(&(philos[i]), argv);
		philos[i].eating = 0;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_time();
		philos[i].start_time = get_time();
		philos[i].dead = &program->dead_flag;
		philos[i].run = &program->run_flag;
		philos[i].r_fork = &forks[i];
		if (i == (ft_atoi(argv[1]) - 1))
			philos[i].l_fork = &forks[0];
		else
			philos[i].l_fork = &forks[i + 1];
		philos[i].write_lock = &program->write_lock;
		philos[i].dead_lock = &program->dead_lock;
		if (pthread_mutex_init(&philos[i].meal_lock, NULL) != 0)
			return (init_exit(program, forks, philos->num_of_philos, i));
		philos[i].run_lock = &program->run_lock;
		philos[i].start_lock = &program->start_lock;
		i++;
	}
}

void	print_philo(t_philo *p)
{
	printf("id:{%d}\n", p->id);
	printf("eating:{%d}\n", p->eating);
	printf("meals_eaten:{%d}\n", p->meals_eaten);
	printf("num_of_philos:{%d}\n", p->num_of_philos);
}
