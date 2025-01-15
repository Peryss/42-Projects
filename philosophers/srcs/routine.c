/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:35:48 by pvass             #+#    #+#             */
/*   Updated: 2024/12/12 13:42:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	p_sleep(t_philo *philo)
{
	//check_safe_exit_thread(philo);
	print_msg("is sleeping", philo);
	p_sleep_nomsg(philo->time_to_sleep, philo);
}

void	p_think(t_philo *philo)
{
	//check_safe_exit_thread(philo);
	print_msg("is thinking", philo);
}

t_philo	*p_eat_one(t_philo *philo)
{
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
	philo->eating = 1;
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

int	shift(t_philo *philo)
{
	if (philo->time_to_die - philo->time_to_eat > 2 * philo->time_to_sleep)
		return (philo->time_to_sleep);
	else
		return (philo->time_to_die - philo->time_to_eat);
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
		if (philo->num_of_philos % 2 == 1 && philo->meals_eaten == 0)
		{
			if (philo->id % 2 == 1)
				p_sleep_nomsg(philo->time_to_eat);
			//p_sleep_nomsg((philo->time_to_die - philo->time_to_eat)
			//	/ (philo->num_of_philos) * philo->id);
			p_sleep_nomsg(shift(philo) / (philo->num_of_philos) * philo->id);
		}
		if (philo->id % 2 == 0)
			philo = p_eat_one(philo); //UGYANAAAAAAz
		else
			philo = p_eat_two(philo); //UGYANAAAAAAAAAAAAAAAAAAAAAAAZ
		p_sleep(philo);
	}
	return (NULL);
}
