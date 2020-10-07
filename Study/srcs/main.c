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

#include "../incl/fractal.h"

char	*get_fractal_name(char *str)
{
	if (ft_strcmp(str, "burningship") == 0 || ft_strcmp(str, "julia") == 0\
				|| ft_strcmp(str, "mandelbrot") == 0 ||\
				ft_strcmp(str, "flame") == 0 ||\
				ft_strcmp(str, "chaosgame") == 0)
		return (str);
	else
	{
		print_usage();
		return (NULL);
	}
}

void	fractal_init(t_fractal **fra, char *name, t_mouse **mouse)
{
	(*mouse) = (t_mouse *)malloc(sizeof(t_mouse));
	(*mouse)->mouse_x = 0.0;
	(*mouse)->mouse_y = 0.0;
	(*mouse)->mouse_disable = 0;
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

void	combi_init(t_combi **combi, t_fractal *fra, t_mouse *mouse)
{
	*combi = (t_combi *)malloc(sizeof(t_combi));
	(*combi)->fra = fra;
	(*combi)->mouse = mouse;
	if (ft_strcmp(fra->name, "chaosgame") != 0 &&\
							ft_strcmp(fra->name, "flame") != 0)
		show_str_in_image(fra);
}

void	print_usage(void)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd("./fractol [fractal type name]\n", STDERR_FILENO);
	ft_putstr_fd("fractal type:\tjulia\t", STDERR_FILENO);
	ft_putstr_fd("mandelbrot\tburningship\tchaosgame\tflame\n", STDERR_FILENO);
}

int		main(int argc, char **argv)
{
	char		*fra_name;
	t_fractal	*fra;
	t_mouse		*mouse;
	t_combi		*combi;

	if (argc == 2)
	{
		if ((fra_name = get_fractal_name(argv[1])) == NULL)
			return (0);
		fractal_init(&fra, fra_name, &mouse);
		if (ft_strcmp(fra->name, "burningship") == 0)
			draw_burningship(fra);
		else if (ft_strcmp(fra->name, "mandelbrot") == 0)
			draw_mandelbrot(fra);
		else if (ft_strcmp(fra->name, "julia") == 0)
			draw_julia(fra, mouse);
		else if (ft_strcmp(fra->name, "chaosgame") == 0)
			draw_chaosgame(fra);
		else if (ft_strcmp(fra->name, "flame") == 0)
			draw_flame(fra);
		mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr, fra->img_ptr, 0, 0);
		combi_init(&combi, fra, mouse);
		fractal_controls(combi);
		mlx_loop(fra->mlx_ptr);
	}
	else
		print_usage();
	return (0);
}
