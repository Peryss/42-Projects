/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:49:04 by pvass             #+#    #+#             */
/*   Updated: 2024/10/25 14:59:47 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char ** argv)
{
	t_program		program;
	t_philo			philos[PHILO_MAX];
	pthread_mutex_t	forks[PHILO_MAX];

	if (argc != 5 && argc != 6)
		return (write(2, "Program works with 4 or 5 arguments\n", 37), 1);
	if (invalid_args(argv) == 1)
		return (1);
	init_program(&program, philos);
	init_forks(forks, argv);
	init_philosophers(&program, philos, forks, argv);
	return (0);
}
