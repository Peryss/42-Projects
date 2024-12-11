/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:35:48 by pvass             #+#    #+#             */
/*   Updated: 2024/12/11 19:42:35 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

t_philo	*p_eat_one(t_philo *philo)
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
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_time();
	philo->meals_eaten++;
	print_msg("is eating", philo);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_lock);
	p_sleep_nomsg(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (philo);
}

t_philo	*p_eat_two(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		p_sleep_nomsg(philo->time_to_die);
		pthread_mutex_unlock(philo->l_fork);
		return (philo);
	}
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo);
	philo->eating = 1;
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_time();
	philo->meals_eaten++;
	print_msg("is eating", philo);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_lock);
	p_sleep_nomsg(philo->time_to_eat);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (philo);
}

void	*routine(void *content)
{
	t_philo	*philo;

	philo = content;
	while (run_and_not_dead(philo) == 1)
	{
		p_think(philo);
		if (philo->num_of_philos % 2 == 1 && philo->meals_eaten == 0)
		{
			if (philo->id % 2 == 1)
				p_sleep_nomsg(philo->time_to_eat);
			p_sleep_nomsg((philo->time_to_die - philo->time_to_eat)
				/ (philo->num_of_philos) * philo->id);
		}
		if (philo->id % 2 == 0)
			philo = p_eat_one(philo);
		else
			philo = p_eat_two(philo);
		p_sleep(philo);
	}
	return (philo);
}
