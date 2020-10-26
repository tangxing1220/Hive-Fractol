/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:00:23 by xtang             #+#    #+#             */
/*   Updated: 2020/10/23 11:00:19 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	print_usage(void)
{
	ft_putstr_fd("usage: ", STDERR_FILENO);
	ft_putstr_fd("./fractol [fractal type name]\n", STDERR_FILENO);
	ft_putstr_fd("fractal type:\tjulia\t", STDERR_FILENO);
	ft_putstr_fd("mandelbrot\tburningship\tchaosgame\tflame\n", STDERR_FILENO);
}

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

void	fractal_show(t_fractal *fra)
{
	mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr, fra->img_ptr, 0, 0);
	show_str_in_image(fra);
	mlx_loop(fra->mlx_ptr);
}

int		main(int argc, char **argv)
{
	char		*fra_name;
	t_fractal	*fra;
	t_mouse		*mouse;

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
		fractal_show(fra);
	}
	else
		print_usage();
	return (0);
}
