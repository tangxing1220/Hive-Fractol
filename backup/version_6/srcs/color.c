/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:11:40 by xtang             #+#    #+#             */
/*   Updated: 2020/08/27 19:31:50 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int		color_rgb_pattern(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int		get_color_pattern(int color_index, int i)
{
	if (color_index == 1)
		return (color_rgb_pattern(i, 0, 0));
	else if (color_index == 2)
		return (color_rgb_pattern(0, i, 0));
	else if (color_index == 3)
		return (color_rgb_pattern(0, 0, i));
	else if (color_index == 4)
		return (color_rgb_pattern(i, i, 0));
	else if (color_index == 5)
		return (color_rgb_pattern(i, i, i));
	else if (color_index == 6)
		return (color_rgb_pattern(0, i, i));
	else
		return (color_rgb_pattern(i, 0, i));
}

int		assign_col(double newre, double newim, int i, t_fractal *fra)
{
	double	iter;
	int		color_value;

	iter = (double)i;
	if (i == 0)
	{
		color_value = 0;
	}
	else
	{
		iter = iter - log(log(sqrt(newre * newre + newim * newim))) / log(2);
		iter = (767 * iter) / fra->maxiterate;
		color_value = get_color_pattern(fra->choose_color, iter);
	}
	return (color_value);
}

void	color_pattern(int key, t_combi *combi)
{
	if (key == MAIN_1)
		combi->fra->choose_color = 1;
	else if (key == MAIN_2)
		combi->fra->choose_color = 2;
	else if (key == MAIN_3)
		combi->fra->choose_color = 3;
	else if (key == MAIN_4)
		combi->fra->choose_color = 4;
	else if (key == MAIN_5)
		combi->fra->choose_color = 5;
	else if (key == MAIN_6)
		combi->fra->choose_color = 6;
	else if (key == MAIN_7)
		combi->fra->choose_color = 7;
	change_color(combi->fra, combi->mouse);
}

void	change_color(t_fractal *fra, t_mouse *mouse)
{
	if (ft_strcmp(fra->name, "julia") == 0)
	{
		draw_julia(fra, mouse);
		mlx_put_image_to_window(fra->mlx_ptr,\
				fra->win_ptr, fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(fra->name, "mandelbrot") == 0)
	{
		draw_mandelbrot(fra);
		mlx_put_image_to_window(fra->mlx_ptr,\
				fra->win_ptr, fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(fra->name, "burningship") == 0)
	{
		draw_burningship(fra);
		mlx_put_image_to_window(fra->mlx_ptr,\
				fra->win_ptr, fra->img_ptr, 0, 0);
	}
}
