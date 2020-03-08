/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:33:17 by xtang             #+#    #+#             */
/*   Updated: 2020/03/05 00:33:20 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "color.h"
#include "error_message.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

void    put_pixel(t_frac *frac, int x, int y, int color)
{
    int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * frac->bits_per_pixel / 8 ) + (y * frac->size_line);
		frac->data_addr[i] = color;
		frac->data_addr[++i] = color >> 8;
		frac->data_addr[++i] = color >> 16;
	}

}

int get_color_pattern(int color_index, double iter)
{
	int color_r;
	int color_g;
	int color_b;
	int color_value;

	color_r = 0;
	color_g = 0;
	color_b = 0;
	color_value = 0;

	if (color_index == 1)
	{
		color_r = iter;
		color_g = 0;
		color_b = 0;
	}
	else if (color_index == 2)
	{
		color_r = 0;
		color_g = iter;
		color_b = 0;
	}
	else if (color_index == 3)
	{
		color_r = 0;
		color_g = 0;
		color_b = iter;
	}
	else if (color_index == 4)
	{
		color_r = iter;
		color_g = iter;
		color_b = 0;
	}
	else if (color_index == 5)
	{
		color_r = iter;
		color_g = iter;
		color_b = iter;
	}
	else if (color_index == 6)
	{
		color_r = 0;
		color_g = iter;
		color_b = iter;
	}
	else if (color_index == 7)
	{
		color_r = iter;
		color_g = 0;
		color_b = iter;
	}
	color_value = (color_r << 16) + (color_g << 8) + color_b;
	return (color_value);
}



int     get_color(t_frac *frac, double newRe, double newIm, int i)
{
	int			color_value;
	double 		iter;

	iter = i - log(log(sqrt( newRe * newRe + newIm * newIm))) / log(2);
	iter = (767 * iter) / frac->control->maxIterate;
	color_value = get_color_pattern(frac->control->select_color, iter);
	return (color_value);
}