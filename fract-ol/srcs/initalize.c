/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:58:17 by pvass             #+#    #+#             */
/*   Updated: 2024/06/11 19:12:17 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

t_fractal	*fract_init(t_fractal *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 300;
	fractal->color = 100;
	fractal->max_iterations = 40;
	fractal->offset_x = -1.2;
	fractal->offset_y = -1.2;
	fractal->mlx = mlx_init();
	if (fractal->mlx == NULL)
		return (NULL);
	fractal->window = mlx_new_window(fractal->mlx, SIZE, SIZE, "Fract-ol");
	if (fractal->window == NULL)
		return (mlx_destroy_display(fractal->mlx), free(fractal->mlx), NULL);
	fractal->image = mlx_new_image(fractal->mlx, SIZE, SIZE);
	if (fractal->image == NULL)
		return (mlx_destroy_display(fractal->mlx), free(fractal->mlx), mlx_destroy_window(fractal->mlx, fractal->window), NULL);
	fractal->pointer_to_image = mlx_get_data_addr(fractal->image,
			&fractal->bits_per_pixel,
			&fractal->size_line,
			&fractal->endian);
	if (fractal->pointer_to_image == NULL)
		return (NULL);
	return(fractal);
}
