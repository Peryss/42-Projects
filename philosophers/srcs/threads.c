/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:57:23 by pvass             #+#    #+#             */
/*   Updated: 2025/01/15 16:56:55 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_and_destroy_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	pthread_mutex_lock(&program->start_lock);
	if (pthread_create(&observer, NULL, observe, program) != 0)
		return (safe_exit("Thread create error", program, forks, 2));
	i = 0;
	while (i < program->philos->num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, routine,
				&program->philos[i]) != 0)
			return (safe_exit("Thread create error", program, forks, 2));
		i++;
	}
	pthread_mutex_unlock(&program->start_lock);
	if (pthread_join(observer, NULL) != 0)
		return (safe_exit("Thread join error", program, forks, 4));
	i = 0;
	while (i < program->philos->num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (safe_exit("Thread join error", program, forks, 4));
		i++;
	}
	return (safe_exit("Finished", program, forks, 0));
}
