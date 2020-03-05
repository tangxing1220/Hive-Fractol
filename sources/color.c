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



int     get_color(double newRe, double newIm, int maxIterate,  int i)
{
	t_color		*color;
	double 		iter;
	int			select_color;


	select_color = 6;

		iter = i - log(log(sqrt( newRe * newRe + newIm * newIm))) / log(2);
		iter = (767 * iter) / maxIterate;
		if (!(color = (t_color *)malloc(sizeof(t_color))))
			terminate(ERR_GET_COLOR);
		if (select_color == 0)
		{
			color->r = 0;
			color->g = 0;
			color->b = 0;
		}
		else if (select_color == 1)
		{
			color->r = iter;
			color->g = 0;
			color->b = 0;
		}
		else if (select_color == 2)
		{
			color->r = 0;
			color->g = iter;
			color->b = 0;
		}
		else if (select_color == 3)
		{
			color->r = 0;
			color->g = 0;
			color->b = iter;
		}
		else if (select_color == 4)
		{
			color->r = iter;
			color->g = iter;
			color->b = 0;
		}
		else if (select_color == 5)
		{
			color->r = iter;
			color->g = iter;
			color->b = iter;
		}
		else if (select_color == 6)
		{
			color->r = 0;
			color->g = iter;
			color->b = iter;
		}
		else if (select_color == 7)
		{
			color->r = iter;
			color->g = 0;
			color->b = iter;
		}
		color->decimal = (color->r << 16) + (color->g << 8) + color->b;
	return (color->decimal);
}