/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:22:46 by pvass             #+#    #+#             */
/*   Updated: 2024/06/02 17:25:56 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractal.h"

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}*/

void	f_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->pointer_to_image + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/*typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;*/

/*int	close_win(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}*/

/* int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
	mlx_loop_hook(vars.win, )
	mlx_loop(vars.mlx);
} */

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	
	if (argc < 2)
		return (ft_putendl_fd(
			"Wrong input! Choose one of the models: mandel, julia", 1), 1);
	fract_init(&fractal);
	if (wrong_input(argc, argv, &fractal) == 1)
		return (0);
	draw_fractal(&fractal, argv[1]);
	mlx_put_image_to_window(fractal.mlx, fractal.window, fractal.image, 0, 0);
	mlx_loop(fractal.mlx);
}
