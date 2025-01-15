/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:53:17 by pvass             #+#    #+#             */
/*   Updated: 2024/12/12 13:58:41 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	safe_exit(char *str, t_program *program,
		pthread_mutex_t *forks, int error)
{
	int	i;
	i = 0;
	if (str && error == 1)
		write (2, str, ft_strlen(str));
	pthread_mutex_unlock(&program->write_lock);
	//program->philos->run = 0;
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->run_lock);
	pthread_mutex_destroy(&program->start_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		pthread_mutex_destroy(&program->philos[i].meal_lock);
		i++;
	}
	//if (error != 0)
		//exit(error);
}

void	init_exit(t_program *program, pthread_mutex_t *forks, int fork, int m)
{
	int	i;

	i = 0;
	printf("I AM HEREEEEE");
	pthread_mutex_destroy(&program->write_lock);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->run_lock);
	pthread_mutex_destroy(&program->start_lock);
	while (i < fork)
	{
		pthread_mutex_destroy(&forks[i]);
		if (m > i)
			pthread_mutex_destroy(&program->philos[i].meal_lock);
		i++;
	}
	write(2, "Mutex init error\n", 18);
	exit(4);
}
