/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:57:23 by pvass             #+#    #+#             */
/*   Updated: 2024/12/12 13:54:18 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	create_and_destroy_threads(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			num_philos;
	int			i;

	pthread_mutex_lock(&program->start_lock);
	num_philos = program->philos->num_of_philos;
	if (pthread_create(&observer, NULL, observe, program->philos) != 0)
		return (safe_exit("Thread create error", program, forks, 2));
	i = 0;
	while (i < num_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, routine,
				&program->philos[i]) != 0)
			return (safe_exit("Thread create error", program, forks, 2));
		i++;
	}
	pthread_mutex_unlock(&program->start_lock);
	//if (pthread_join(observer, NULL) != 0)
		//return (safe_exit("Thread join error", program, forks, 3));
	i = 0;
	//printf("asdasdasd\n");
	while (i < num_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			return (safe_exit("Thread join error", program, forks, 3));
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		return (safe_exit("Thread join error", program, forks, 3));
	/* pthread_mutex_lock(program->philos->write_lock);
	printf("asdasdasasdasdasdd\n");
	pthread_mutex_unlock(program->philos->write_lock); */
	return (safe_exit("Finished", program, forks, 0));
}
