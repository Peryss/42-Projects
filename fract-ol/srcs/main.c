/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:22:46 by pvass             #+#    #+#             */
/*   Updated: 2024/06/12 16:31:56 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int	main(int argc, char **argv)
{
	t_fractal	*fractal;

	if (argc < 2)
		return (ft_putendl_fd(
				"Choose one of the models: mandel, julia, ship", 1), 0);
	fractal = malloc (sizeof(t_fractal));
	if (fractal == NULL)
		return (ft_putendl_fd("Malloc failed\n", 1), 0);
	if (wrong_input(argc, argv, fractal) == 1)
		return (free(fractal), 0);
	if (fract_init(fractal) == NULL)
		return (free(fractal), ft_putendl_fd("Mlx failed\n", 1), 0);
	draw_fractal(fractal, argv[1]);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_program, fractal);
	mlx_loop(fractal->mlx);
}
