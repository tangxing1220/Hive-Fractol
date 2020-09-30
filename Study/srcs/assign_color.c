/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:36:20 by xtang             #+#    #+#             */
/*   Updated: 2020/09/08 12:36:27 by xtang            ###   ########.fr       */
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

int		assign_color(double newre, double newim, int i, t_fractal *fra)
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

void	draw_pixel(t_fractal *fra, int x, int y, int col)
{
	int i;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		i = (x * (fra->bits_per_pixel / 8) + y * fra->size_line);
		fra->data_addr[i] = col;
		fra->data_addr[++i] = col >> 8;
		fra->data_addr[++i] = col >> 16;
	}
}
