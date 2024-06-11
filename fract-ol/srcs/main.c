/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:22:46 by pvass             #+#    #+#             */
/*   Updated: 2024/06/11 18:59:53 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	f_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->pointer_to_image + (y * fractal->size_line + x * (fractal->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	exit_program (t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx, fractal->image);
	mlx_destroy_window(fractal->mlx, fractal->window);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	exit(1);
	return (0);
}

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		exit_program(fractal);
	if (keycode == RIGHT)
		fractal->offset_x += 30 / fractal->zoom;
	if (keycode == LEFT)
		fractal->offset_x -= 30 / fractal->zoom;
	if (keycode == UP)
		fractal->offset_y += 30 / fractal->zoom;
	if (keycode == DOWN)
		fractal->offset_y -= 30 / fractal->zoom;
	if (keycode == W && ft_strncmp(fractal->name, "julia", 5) == 0)
		fractal->cx += 0.03;
	if (keycode == S && ft_strncmp(fractal->name, "julia", 5) == 0)
		fractal->cx -= 0.03;
	if (keycode == A && ft_strncmp(fractal->name, "julia", 5) == 0)
		fractal->cy += 0.03;
	if (keycode == D && ft_strncmp(fractal->name, "julia", 5) == 0)
		fractal->cy -= 0.03;
	draw_fractal(fractal, fractal->name);
	return (0);
}

int mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == M_UP)
	{
		fractal->offset_x = (fractal->offset_x + x / fractal->zoom)
		 	- (x / (fractal->zoom * 1.2));
		fractal->offset_y = (fractal->offset_y + y / fractal->zoom)
			- (y / (fractal->zoom * 1.2));
		fractal->zoom *= 1.2;
	}
	if (keycode == M_DOWN)
	{
		fractal->offset_x = (fractal->offset_x + x / fractal->zoom)
			- (x / (fractal->zoom / 1.2));
		fractal->offset_y = (fractal->offset_y + y / fractal->zoom)
			- (y / (fractal->zoom / 1.2));
		fractal->zoom /= 1.2;	
	}
	draw_fractal(fractal, fractal->name);
	return(0);
}

int	main(int argc, char **argv)
{
	t_fractal	*fractal;
	
	if (argc < 2)
		return (ft_putendl_fd(
			"Wrong input! Choose one of the models: mandel, julia", 1), 0);
	fractal = malloc (sizeof(t_fractal));
	if(fractal == NULL)
		return (ft_putendl_fd("Malloc failed\n", 1), 0);
	if (wrong_input(argc, argv, fractal) == 1)
		return (free(fractal), 0);
	if(fract_init(fractal) == NULL)
		return (free(fractal), ft_putendl_fd("Mlx failed\n", 1), 0);
	draw_fractal(fractal, argv[1]);
	mlx_key_hook(fractal->window, key_hook, fractal);
	mlx_mouse_hook(fractal->window, mouse_hook, fractal);
	mlx_hook(fractal->window, 17, 0L, exit_program, fractal);
	mlx_loop(fractal->mlx);
}
