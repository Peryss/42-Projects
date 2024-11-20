/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:35:48 by pvass             #+#    #+#             */
/*   Updated: 2024/11/06 15:41:43 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	 print_msg(char *msg, t_philo *philos)
{
	size_t	t;

	pthread_mutex_lock(philos->run_lock);
	if (*philos[0].dead == 1)
	{
		pthread_mutex_unlock(philos->run_lock);
		return ;
	}
	pthread_mutex_unlock(philos->run_lock);
	pthread_mutex_lock(philos->write_lock);
	t = get_time() - philos->start_time; 
	printf("%zu	%d	%s\n", t, philos->id, msg);
	pthread_mutex_unlock(philos->write_lock);
}

void	p_sleep_nomsg(size_t time)
{
	size_t	start;

	if (time == 0)
		return ;
	start = get_time();
	while (get_time() - start < time)
		usleep(100);
}

void	p_sleep(t_philo *philo)
{	
	check_safe_exit_thread(philo);
	print_msg("is sleeping", philo);
	p_sleep_nomsg(philo->time_to_sleep);
}
void	p_think(t_philo *philo)
{
	check_safe_exit_thread(philo);
	print_msg("is thinking", philo);
}

t_philo	*p_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		p_sleep_nomsg(philo->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return (philo);
	}
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken a fork", philo);
	print_msg("is eating", philo);
	philo->eating = 1; 
	pthread_mutex_lock(philo->meal_lock);
	//maybe here
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	p_sleep_nomsg(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (philo);
}

void	check_safe_exit_thread(t_philo *philo)
{
	pthread_mutex_lock(philo->run_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->run == 0 || *philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->run_lock);
		exit(0);
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->run_lock);
}

void	*routine(void *content)
{
	t_philo	*philo;

	philo = content;
	if (philo->id % 2 == 1)
		p_sleep_nomsg(1);
	pthread_mutex_lock(philo->run_lock);
	pthread_mutex_lock(philo->dead_lock);
	//printf("Start philo{%d}\n", philo->id);
	while (*philo->run == 1 && *philo->dead == 0)
	{
		pthread_mutex_unlock(philo->dead_lock);
		pthread_mutex_unlock(philo->run_lock);
		philo = p_eat(philo);
		//printf("retart philo1{%d}\n", philo->id);
		p_sleep(philo);
		//printf("retart philo2{%d}\n", philo->id);
		p_think(philo);
		//printf("retart philo3{%d}\n", philo->id);
		//exit(0);
		pthread_mutex_lock(philo->run_lock);
		pthread_mutex_lock(philo->dead_lock);
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->run_lock);
	return (philo);
}
