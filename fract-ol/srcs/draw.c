/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:26:30 by pvass             #+#    #+#             */
/*   Updated: 2024/06/12 15:52:54 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

void	calc_mandel(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->name = "mandel";
	fractal->zx = 0;
	fractal->zy = 0;
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (i < fractal->max_iterations)
	{
		temp = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2. * fractal->zx * fractal->zy + fractal->cy;
		fractal->zx = temp;
		if (fractal->zx * fractal->zx
			+ fractal->zy * fractal->zy >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == fractal->max_iterations)
		f_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		f_mlx_pixel_put(fractal, fractal->x, fractal->y,
			(fractal->color + fractal->r * i * 4));
}

void	draw_mandel(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calc_mandel(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

void	calc_julia(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->name = "julia";
	fractal->zx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->zy = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (i < fractal->max_iterations)
	{
		temp = fractal->zx;
		fractal->zx = fractal->zx * fractal->zx
			- fractal->zy * fractal->zy + fractal->cx;
		fractal->zy = 2 * fractal->zy * temp + fractal->cy;
		if (fractal->zx * fractal->zx
			+ fractal->zy * fractal->zy >= __DBL_MAX__)
			break ;
		i++;
	}
	if (i == fractal->max_iterations)
		f_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		f_mlx_pixel_put(fractal, fractal->x, fractal->y,
			(fractal->color + fractal->r * i * 4));
}

void	draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calc_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}

void	draw_fractal(t_fractal *fractal, char *name)
{
	if (fractal->mlx == NULL)
		return ;
	if (ft_strncmp(name, "mandel", 7) == 0)
	{
		draw_mandel(fractal);
	}
	else if (ft_strncmp(name, "julia", 6) == 0)
	{
		draw_julia(fractal);
	}
	else if (ft_strncmp(name, "ship", 4) == 0)
	{
		draw_ship(fractal);
	}
	else
		ft_putendl_fd(
			"Available fractals: julia, mandel, ship", 1);
	mlx_put_image_to_window(fractal->mlx, fractal->window,
		fractal->image, 0, 0);
	return ;
}
