/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:57:12 by xtang             #+#    #+#             */
/*   Updated: 2020/09/02 18:58:30 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	mandelbrot_cacul(int width, int height, t_complex max,\
			t_fractal *fra, t_complex factor, t_complex min)
{
	t_complex	new;
	t_complex	old;
	t_complex	c;
	int			i;

	c.im = max.im * (fra->zoom) - height * factor.im + fra->offset_y;
	c.re = min.re * (fra->zoom) + width * factor.re +
				fra->offset_x;
	new.re = c.re;
	new.im = c.im;
	i = 0;
	while (i < fra->maxiterate)
	{
		old.re = new.re;
		old.im = new.im;
		new.re = old.re * old.re - old.im * old.im + c.re;
		new.im = 2 * old.re * old.im + c.im;
		if ((new.re * new.re + new.im * new.im) > 4)
			break ;
		i++;
	}
	draw_pixel(fra, width, height,\
				assign_col(new.re, new.im, i, fra));
}

void	draw_mandelbrot(t_fractal *fra)
{
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	int			width;
	int			height;

	min.re = -2.05;
	max.re = 0.95;
	min.im = -1.5;
	max.im = min.im + (max.re - min.re) * HEIGHT / WIDTH;
	factor.re = (max.re - min.re) * (fra->zoom) / (WIDTH - 1);
	factor.im = (max.im - min.im) * (fra->zoom) / (HEIGHT - 1);
	height = 0;
	while (height < HEIGHT)
	{
		width = 0;
		while (width < WIDTH)
		{
			mandelbrot_cacul(width, height, max, fra, factor, min);
			width++;
		}
		height++;
	}
}
