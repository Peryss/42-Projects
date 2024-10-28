/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:35:48 by pvass             #+#    #+#             */
/*   Updated: 2024/10/28 17:44:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(char *msg, t_philo *philos)
{
	size_t	t;

	pthread_mutex_lock(philos[0].dead_lock);
	if (*philos[0].dead == 1)
		return ;
	pthread_mutex_unlock(philos[0].dead_lock);
	pthread_mutex_lock(philos[0].write_lock);
	t = get_time() - philos->start_time; 
	printf("%zu	%d	%s\n", t, philos[0].id, msg);
	pthread_mutex_unlock(philos[0].write_lock);
}

void	p_sleep_nomsg(size_t time)
{
	usleep(time*100);
}

void	p_sleep(t_philo *philo)
{	
	print_msg("is sleeping", philo);
	p_sleep_nomsg(philo->time_to_die);
}
void	p_think(t_philo *philo)
{
	print_msg("is thinking", philo);
}

void	p_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		p_sleep_nomsg(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken a fork", philo);
	print_msg("is eating", philo);
	philo->eating = 1;
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	p_sleep_nomsg(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}



void	*routine(void *content)
{
	t_philo	*philo;

	philo = content;
	if (philo->id % 2 == 1)
		p_sleep_nomsg(1);
	while (*(philo->dead) == 0)
	{
		p_eat(philo);
		p_sleep(philo);
		p_think(philo);
	}
	return (philo);
}
