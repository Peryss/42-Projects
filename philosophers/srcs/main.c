/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:49:04 by pvass             #+#    #+#             */
/*   Updated: 2024/12/11 19:40:12 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[200];
	pthread_mutex_t	forks[200];

	if (argc != 5 && argc != 6)
		return (write(2, "Program works with 4 or 5 arguments\n", 37), 1);
	if (invalid_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, argv);
	init_philosophers(&program, philos, forks, argv);
	create_and_destroy_threads(&program, forks);
	return (0);
}
