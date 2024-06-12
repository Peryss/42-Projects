/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:31:13 by pvass             #+#    #+#             */
/*   Updated: 2024/06/12 16:34:47 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	f_mlx_pixel_put(t_fractal *fractal, int x, int y, int color)
{
	char	*dst;

	dst = fractal->pointer_to_image + (y * fractal->size_line
			+ x * (fractal->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_program(t_fractal *fractal)
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
	if (keycode == C)
		fractal->r = fractal-> r * 256 % (255 * 255 * 255);
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	mouse_hook(int keycode, int x, int y, t_fractal *fractal)
{
	if (keycode == M_UP)
	{
		fractal->offset_x = (fractal->offset_x + x / fractal->zoom)
			- (x / (fractal->zoom * 1.2));
		fractal->offset_y = (fractal->offset_y + y / fractal->zoom)
			- (y / (fractal->zoom * 1.2));
		fractal->zoom *= 1.2;
		fractal->r = fractal->r + 256 * 256;
	}
	if (keycode == M_DOWN)
	{
		fractal->offset_x = (fractal->offset_x + x / fractal->zoom)
			- (x / (fractal->zoom / 1.2));
		fractal->offset_y = (fractal->offset_y + y / fractal->zoom)
			- (y / (fractal->zoom / 1.2));
		fractal->zoom /= 1.2;
		fractal->r = fractal->r + 256 * 256;
	}
	draw_fractal(fractal, fractal->name);
	return (0);
}

int	wrong_for_julia(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] != '.')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	if (str[i] == '.')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}
