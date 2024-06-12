/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:40:33 by pvass             #+#    #+#             */
/*   Updated: 2024/06/12 16:44:07 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

/*z = (|R(z)| + i|C(z)|) ^ 2 + c*/

double	ft_abs(double nr)
{
	if (nr < 0)
		return (nr * -1.0);
	return (nr);
}

void	calc_ship(t_fractal *fractal)
{
	int		i;
	double	temp;

	i = 0;
	fractal->name = "ship";
	fractal->cx = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->cy = (fractal->y / fractal->zoom) + fractal->offset_y;
	fractal->zx = 0.0;
	fractal->zy = 0.0;
	while (i++ < fractal->max_iterations && fractal->zx * fractal->zx
		+ fractal->zy * fractal->zy < 4)
	{
		temp = ft_abs(fractal->zx * fractal->zx - fractal->zy * fractal->zy
				+ fractal->cx);
		fractal->zy = ft_abs(2.0 * fractal->zy * fractal->zx) + fractal->cy;
		fractal->zx = temp;
		if (fractal->zx * fractal->zx
			+ fractal->zy * fractal->zy >= __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iterations + 1)
		f_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		f_mlx_pixel_put(fractal, fractal->x, fractal->y,
			(fractal->color + fractal->r * i * 4));
}

void	draw_ship(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	while (fractal->x < SIZE)
	{
		fractal->y = 0;
		while (fractal->y < SIZE)
		{
			calc_ship(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
}
