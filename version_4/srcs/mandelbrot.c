/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:57:12 by xtang             #+#    #+#             */
/*   Updated: 2020/08/27 20:30:41 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	draw_mandelbrot(t_fractal *fractal)
{
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	double	minre;
	double	maxre;
	double	minim;
	double	maxim;
	double	re_factor;
	double	im_factor;
	int		i;
	int		width;
	int		height;
	int		col;

	minre = -2.05;
	maxre = 0.95;
	minim = -1.5;
	maxim = minim + (maxre - minre) * HEIGHT / WIDTH;
	re_factor = (maxre - minre) * (fractal->zoom) / (WIDTH - 1);
	im_factor = (maxim - minim) * (fractal->zoom) / (HEIGHT - 1);
	height = 0;
	while (height < HEIGHT)
	{
		cim = maxim * (fractal->zoom) - height * im_factor + fractal->offset_y;
		width = 0;
		while (width < WIDTH)
		{
			cre = minre * (fractal->zoom) + width * re_factor +
				fractal->offset_x;
			newre = cre;
			newim = cim;
			i = 0;
			while (i < fractal->maxiterate)
			{
				oldre = newre;
				oldim = newim;
				newre = oldre * oldre - oldim * oldim + cre;
				newim = 2 * oldre * oldim + cim;
				if ((newre * newre + newim * newim) > 4)
					break ;
				i++;
			}
			col = assign_col(newre, newim, i, fractal);
			draw_pixel(fractal, width, height, col);
			width++;
		}
		height++;
	}
}
