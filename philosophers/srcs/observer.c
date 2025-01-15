/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:47:28 by pvass             #+#    #+#             */
/*   Updated: 2025/01/15 17:54:53 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	all_ate_enough(t_philo *philos)
{
	int	i;
	int	done;

	i = 0;
	done = 0;
	pthread_mutex_lock(philos->start_lock);
	pthread_mutex_unlock(philos->start_lock);
	if (philos[i].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(&philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			done++;
		pthread_mutex_unlock(&philos[i].meal_lock);
		i++;
	}
	if (done == philos[0].num_of_philos)
		return (1);
	return (0);
}

int	is_dead(t_philo *philos)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&philos->meal_lock);
	if (philos->eating == 0
		&& ((get_time() - philos->last_meal) > philos->time_to_die))
		res = 1;
	pthread_mutex_unlock(&philos->meal_lock);
	return (res);
}

void	set_to_finished(t_program *program)
{
	pthread_mutex_lock(&program->run_lock);
	program->run_flag = 0;
	pthread_mutex_unlock(&program->run_lock);
}

int	finished(t_program *program)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = program->philos;
	while (i < philos[0].num_of_philos)
	{
		if (is_dead(&philos[i]) == 1)
		{
			set_to_finished(program);
			print_died(&philos[i]);
			return (1);
		}
		i++;
	}
	if (all_ate_enough(philos) == 1)
	{
		pthread_mutex_lock(philos->run_lock);
		program->run_flag = 0;
		pthread_mutex_unlock(philos->run_lock);
		return (1);
	}
	return (0);
}

void	*observe(void *pointer)
{
	t_program	*program;

	program = pointer;
	while (1)
	{
		if (finished(program) == 1)
			break ;
		usleep(5);
	}
	return (pointer);
}
