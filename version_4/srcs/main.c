/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:00:23 by xtang             #+#    #+#             */
/*   Updated: 2020/08/27 19:08:43 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	print_usage(void)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd("./fractol [fractal type name]\n", STDERR_FILENO);
	ft_putstr_fd("fractal type:\tjulia\t", STDERR_FILENO);
	ft_putstr_fd("mandelbrot\tburningship\n", STDERR_FILENO);
}

void	draw_image_blackground(t_fractal *fractal)
{
	int i;
	int *pixel;

	i = 0;
	if ((fractal->bits_per_pixel / 8) == 4)
		pixel = (int *)(fractal->data_addr);
	while (i < HEIGHT * WIDTH)
	{
		pixel[i] = COL_BACKGROUND;
		i++;
	}
}

void	mouse_init(t_mouse **mouse)
{
	(*mouse) = (t_mouse *)malloc(sizeof(t_mouse));
	(*mouse)->mouse_x = 0.0;
	(*mouse)->mouse_y = 0.0;
	(*mouse)->mouse_disable = 0;
}

int		main(int argc, char **argv)
{
	t_fractal	*fra;
	t_mouse		*mouse;
	t_combi		*combi;

	if (argc == 2 && (ft_strcmp(argv[1], "burningship") == 0 ||\
				ft_strcmp(argv[1], "julia") == 0\
				|| ft_strcmp(argv[1], "mandelbrot") == 0))
	{
		fra = (t_fractal *)malloc(sizeof(t_fractal));
		fra->mlx_ptr = mlx_init();
		fra->win_ptr = mlx_new_window(fra->mlx_ptr, WIDTH, HEIGHT,\
							"Fractal xtang");
		fra->img_ptr = mlx_new_image(fra->mlx_ptr, WIDTH, HEIGHT);
		fra->data_addr = mlx_get_data_addr(fra->img_ptr, \
				&(fra->bits_per_pixel), &(fra->size_line),\
						&(fra->endian));
		fra->offset_x = 0;
		fra->offset_y = 0;
		fra->zoom = 1;
		fra->choose_color = 1;
		fra->maxiterate = 45;
		mouse_init(&mouse);
		draw_image_blackground(fra);
		if (ft_strcmp(argv[1], "burningship") == 0)
		{
			fra->name = argv[1];
			draw_burningship(fra);
		}
		else if (ft_strcmp(argv[1], "julia") == 0)
		{
			fra->name = argv[1];
			draw_julia(fra, mouse);
		}
		else
		{
			fra->name = argv[1];
			draw_mandelbrot(fra);
		}
		mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr,\
							fra->img_ptr, 0, 0);
		combi_init(&combi, fra, mouse);
		fractal_controls(combi);
		mlx_loop(fra->mlx_ptr);
	}
	else
		print_usage();
	return (1);
}
