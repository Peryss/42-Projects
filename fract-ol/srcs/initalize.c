/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:58:17 by pvass             #+#    #+#             */
/*   Updated: 2024/05/28 15:44:17 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

t_fractal	*fract_init()
{
	t_fractal *fractal;

	fractal = (t_fractal *) malloc (sizeof(t_fractal *));
	if (fractal == NULL)
		return (NULL);
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 300;
	fractal->color = 0xFFFF00;
	fractal->max_iterations = 30;
	fractal->offset_x = -1.21;
	fractal->offset_y = -1.21;
}

t_fractal	*initialize(t_fractal *fractal)
{
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		return (NULL);
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	if (fractal->window == NULL)
		return (NULL);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (fractal->image == NULL)
		return (NULL);
	fractal->pointer_to_image = mlx_get_data_addr(
		fractal->image, fractal->bits_per_pixel,
		fractal->size_line, fractal->endian);
	if (fractal->pointer_to_image == NULL)
		return (NULL);
}
