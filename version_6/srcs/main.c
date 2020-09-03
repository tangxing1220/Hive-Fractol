/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:00:23 by xtang             #+#    #+#             */
/*   Updated: 2020/09/03 15:43:18 by xtang            ###   ########.fr       */
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

void	mouse_init(t_mouse **mouse)
{
	(*mouse) = (t_mouse *)malloc(sizeof(t_mouse));
	(*mouse)->mouse_x = 0.0;
	(*mouse)->mouse_y = 0.0;
	(*mouse)->mouse_disable = 0;
}

void	fractal_init(t_fractal **fra, char *name)
{
	(*fra) = (t_fractal *)malloc(sizeof(t_fractal));
	(*fra)->mlx_ptr = mlx_init();
	(*fra)->win_ptr = mlx_new_window((*fra)->mlx_ptr, WIDTH, HEIGHT, "Fractal");
	(*fra)->img_ptr = mlx_new_image((*fra)->mlx_ptr, WIDTH, HEIGHT);
	(*fra)->data_addr = mlx_get_data_addr((*fra)->img_ptr, \
				&((*fra)->bits_per_pixel), &((*fra)->size_line),\
						&((*fra)->endian));
	(*fra)->offset_x = 0;
	(*fra)->offset_y = 0;
	(*fra)->zoom = 1;
	(*fra)->choose_color = 1;
	(*fra)->maxiterate = 45;
	(*fra)->name = name;
}

char	*get_fractal_name(char *str)
{
	if (ft_strcmp(str, "burningship") == 0 || ft_strcmp(str, "julia") == 0\
				|| ft_strcmp(str, "mandelbrot") == 0)
		return (str);
	else
	{
		print_usage();
		return (NULL);
	}
}

int		main(int argc, char **argv)
{
	t_fractal	*fra;
	t_mouse		*mouse;
	t_combi		*combi;
	char		*fra_name;

	if (argc == 2)
	{
		fra_name = get_fractal_name(argv[1]);
		fractal_init(&fra, fra_name);
		mouse_init(&mouse);
		draw_image_blackground(fra);
		if (ft_strcmp(fra->name, "burningship") == 0)
			draw_burningship(fra);
		else if (ft_strcmp(fra->name, "julia") == 0)
			draw_julia(fra, mouse);
		else
			draw_mandelbrot(fra);
		mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr, fra->img_ptr, 0, 0);
		combi_init(&combi, fra, mouse);
		fractal_controls(combi);
		mlx_loop(fra->mlx_ptr);
	}
	else
		print_usage();
	return (0);
}
