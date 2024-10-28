/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:57:23 by pvass             #+#    #+#             */
/*   Updated: 2024/10/28 17:39:28 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int		all_ate_enough(t_philo *philos)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	if (philos[i].num_times_to_eat == -1)
			return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			done++;
		pthread_mutex_unlock(philos[i].meal_lock);
	}
	if (done == philos[0].num_of_philos)
		return (1);
	return (0);
}

int		is_dead(t_philo *philos)
{
	int	res;

	res = 0;
	pthread_mutex_lock(philos[0].meal_lock);
	if (philos[0].eating == 0 && (get_time() - philos[0].last_meal > philos[0].time_to_die))
		res = 1;
	pthread_mutex_unlock(philos[0].meal_lock);
	return (res);
}

int		finished(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		if (is_dead(&philos[i]) == 1)
		{
			print_msg("died", &philos[i]);
			pthread_mutex_lock(philos[i].dead_lock);
			*philos[i].dead = 1;
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		i++;
	}
	if (all_ate_enough(&philos[0]) == 1)
		return (1);
	return (0);
}

void	*observe(void *pointer)
{
	t_philo	*philos;
	
	philos = pointer;
	while (1)
	{
		if (finished(philos) == 1)
			break;
	}
	//pthread_mutex_lock(philos->write_lock);
	return (pointer);
}

void	destory_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str)
	{
		printf("%s\n", str);
	}
	//pthread_mutex_unlock(&program->write_lock);
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->dead_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

/* void	safe_exit(t_program *program, pthread_mutex_t *forks)
{
	
} */

void	create_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;
	
	(void)forks;
	if (pthread_create(&observer, NULL, observe, program->philos) != 0)
		return /* (safe_exit(program, forks, THREAD_ERROR)) */;
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, routine, &program->philos[i]) != 0)
			return /* (safe_exit(program, forks, THREAD_ERROR)) */;
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		return /* (safe_exit(program, forks, T_JOIN_ERROR) ) */;
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return/*  (safe_exit(program, forks, T_JOIN_ERROR)) */;
		i++;
	}
	destory_all("DONE", program, forks);
}
