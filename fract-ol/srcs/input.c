/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:44 by pvass             #+#    #+#             */
/*   Updated: 2024/06/11 13:36:34 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int		wrong_input(int argc, char **argv, t_fractal *fractal)
{
	if (argc == 2 && ft_strncmp(argv[1], "mandel", 7) == 0)
		return (0);
	if (ft_strncmp(argv[1], "julia", 6) == 0)
	{
		if (argc != 4)
			return(ft_putendl_fd(
				"Wrong input! 2 numeric parameters needed fo the julia set",
				1), ft_putendl_fd("Try ./fractol julia -.01 -.75", 1), 1);
		if (wrong_for_julia(argv[2]) == 1 || wrong_for_julia(argv[3]) == 1)
			return (ft_putendl_fd("Wrong parameters for the julia set", 1),
			ft_putendl_fd("Try ./fractol julia -.01 -.75", 1), 1);
		fractal->cx = atod(argv[2]);
		fractal->cy = atod(argv[3]);
		return (0);
	}
	return (ft_putendl_fd(
		"Model not available. Available model: mandel, julia", 1), 1);
}