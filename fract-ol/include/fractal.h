/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 14:49:55 by pvass             #+#    #+#             */
/*   Updated: 2024/06/11 19:03:02 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <math.h>

# define SIZE	700

# define ESC	65307
# define M_UP	4
# define M_DOWN 5
# define LEFT	65361
# define RIGHT	65363
# define UP		65364
# define DOWN	65362
# define W		119
# define S		115
# define A		97
# define D		100

typedef struct s_fractal
{
	void	*mlx;
	void	*window;
	void	*image;
	char	*pointer_to_image;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		x;
	int		y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	long	color;
	double	offset_x;
	double	offset_y;
	double	zoom;
	char	*name;
	int		max_iterations;
}			t_fractal;

/*Initialize*/

t_fractal	*fract_init(t_fractal *fractal);

void	f_mlx_pixel_put(t_fractal *data, int x, int y, int color);

void	draw_fractal(t_fractal *fractal, char *name);

int		wrong_input(int argc, char **argv, t_fractal *fractal);

int		wrong_for_julia(char *str);

double	atod(char *str);

int		exit_program (t_fractal *fractal);

#endif