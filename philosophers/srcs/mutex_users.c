/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_users.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:29 by pvass             #+#    #+#             */
/*   Updated: 2024/12/11 19:43:15 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_msg(char *msg, t_philo *philos)
{
	size_t	t;

	if (run_and_not_dead(philos) == 0)
		return ;
	pthread_mutex_lock(philos->write_lock);
	t = get_time() - philos->start_time;
	printf("%zu	%d	%s\n", t, philos->id + 1, msg);
	pthread_mutex_unlock(philos->write_lock);
}

int	run_and_not_dead(t_philo *philo)
{
	int	res;

	res = 0;
	pthread_mutex_lock(philo->run_lock);
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->run == 1 && *philo->dead == 0)
		res = 1;
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_unlock(philo->run_lock);
	return (res);
}

void	check_safe_exit_thread(t_philo *philo)
{
	if (run_and_not_dead(philo) == 0)
		exit (0);
}

int	first_meal(t_philo *philo)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&philo->meal_lock);
	if (philo->meals_eaten == 0)
		res = 1;
	pthread_mutex_unlock(&philo->meal_lock);
	return (res);
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
