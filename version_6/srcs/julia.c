/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:54:24 by xtang             #+#    #+#             */
/*   Updated: 2020/09/03 13:30:31 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

static void	julia_caculate(int width, int height, t_fractal *fra,\
								t_complex_plain *plain)
{
	int			i;
	t_complex	c;
	t_complex	new;
	t_complex	old;
	int			color;

	c.re = -0.7 + plain->offset.re;
	c.im = 0.27015 + plain->offset.im;
	new.re = plain->min.re * (fra->zoom) + width * plain->factor.re +\
			fra->offset_x;
	new.im = plain->max.im * (fra->zoom) - height * plain->factor.im +\
			fra->offset_y;
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
	color = assign_col(new.re, new.im, i, fra);
	draw_pixel(fra, width, height, color);
}

static void	complex_plain_init(t_complex_plain *plain, t_fractal *fra,\
					t_mouse *mouse)
{
	plain->min.re = -2.05;
	plain->max.re = 0.95;
	plain->min.im = -1.5;
	plain->max.im = plain->min.im + (plain->max.re - plain->min.re)
									* HEIGHT / WIDTH;
	plain->factor.re = (plain->max.re - plain->min.re) *\
						(fra->zoom) / (WIDTH - 1);
	plain->factor.im = (plain->max.im - plain->min.im) *\
						(fra->zoom) / (HEIGHT - 1);
	plain->offset.re = mouse->mouse_x;
	plain->offset.im = mouse->mouse_y;
}

void		draw_julia(t_fractal *fra, t_mouse *mouse)
{
	t_complex_plain	*plain;
	int				width;
	int				height;

	plain = (t_complex_plain *)malloc(sizeof(t_complex_plain));
	complex_plain_init(plain, fra, mouse);
	height = 0;
	while (height < HEIGHT)
	{
		width = 0;
		while (width < WIDTH)
		{
			julia_caculate(width, height, fra, plain);
			width++;
		}
		height++;
	}
}
