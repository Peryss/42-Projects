/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_users.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:46:29 by pvass             #+#    #+#             */
/*   Updated: 2025/01/15 17:55:13 by pvass            ###   ########.fr       */
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
	(void) res;
	(void) philo;
	pthread_mutex_lock(philo->run_lock);
	if (*philo->run == 1)
		res = 1;
	pthread_mutex_unlock(philo->run_lock);
	return (res);
}

void	p_sleep_nomsg(size_t time, t_philo *philo)
{
	size_t	start;

	if (time == 0)
		return ;
	start = get_time();
	while (get_time() - start < time && run_and_not_dead(philo) == 1)
		usleep(100);
}

void	print_died(t_philo *philos)
{
	size_t	t;

	pthread_mutex_lock(philos->write_lock);
	t = get_time() - philos->start_time;
	printf("%zu	%d	%s\n", t, philos->id + 1, "died");
	pthread_mutex_unlock(philos->write_lock);
}
