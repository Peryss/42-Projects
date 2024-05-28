/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:22:46 by pvass             #+#    #+#             */
/*   Updated: 2024/05/28 15:58:58 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

int main()
{
	t_fractal *fractal;

	fractal = fract_init();
	if (fractal == NULL)
		return (0);
	fractal = initialize(fractal);
	if (fractal == NULL)
		return (0);
	mlx_pixel_put(fractal->mlx, fractal->window, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(fractal->mlx, fractal->window, fractal->pointer_to_image, 5, 5);
	mlx_loop(fractal->mlx);
}