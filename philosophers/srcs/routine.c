/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:35:48 by pvass             #+#    #+#             */
/*   Updated: 2025/01/16 14:52:01 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_sleep(t_philo *philo)
{
	print_msg("is sleeping", philo);
	p_sleep_nomsg(philo->time_to_sleep, philo);
}

void	p_think(t_philo *philo)
{
	print_msg("is thinking", philo);
	if (philo->num_of_philos == 3 && philo->meals_eaten == 0)
	{
		p_sleep_nomsg(philo->time_to_eat * philo->id / 2, philo);
	}
	if (philo->num_of_philos == 3 && philo->meals_eaten > 0)
	{
		if (philo->time_to_eat + 2 > philo->time_to_sleep)
			p_sleep_nomsg(philo->time_to_eat, philo);
		print_msg("after first meal", philo);
	}
}

t_philo	*p_eat_one(t_philo *philo)
{
	if (philo->num_of_philos % 2 == 0 && philo->meals_eaten == 0)
		p_sleep_nomsg (philo->time_to_eat / 2, philo);
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo);
	if (philo->num_of_philos == 1)
	{
		p_sleep_nomsg(philo->time_to_die, philo);
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
	p_sleep_nomsg(philo->time_to_eat, philo);
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
		p_sleep_nomsg(philo->time_to_die, philo);
		pthread_mutex_unlock(philo->l_fork);
		return (philo);
	}
	pthread_mutex_lock(philo->r_fork);
	print_msg("has taken a fork", philo);
	pthread_mutex_lock(&philo->meal_lock);
	philo->eating = 1;
	philo->last_meal = get_time();
	philo->meals_eaten++;
	print_msg("is eating", philo);
	philo->eating = 0;
	pthread_mutex_unlock(&philo->meal_lock);
	p_sleep_nomsg(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
	return (philo);
}

void	*routine(void *content)
{
	t_philo	*philo;

	philo = content;
	pthread_mutex_lock(philo->start_lock);
	pthread_mutex_unlock(philo->start_lock);
	while (run_and_not_dead(philo) == 1)
	{
		p_think(philo);
		if (philo->num_of_philos % 2 == 1 && philo->meals_eaten == 0
			&& philo->num_of_philos != 3)
		{
			if (philo->id % 2 == 1)
				p_sleep_nomsg(philo->time_to_eat, philo);
			if ((philo->num_of_philos != 3 || (philo->num_of_philos == 3
						&& philo->id % 2 == 0)) && philo->num_of_philos != 1)
				p_sleep_nomsg((philo->time_to_eat / ((philo->num_of_philos - 1)
							/ 2)) * philo->id / 2, philo);
		}
		if (philo->id % 2 == 0)
			philo = p_eat_one(philo);
		else
			philo = p_eat_two(philo);
		p_sleep(philo);
	}
	return (NULL);
}
