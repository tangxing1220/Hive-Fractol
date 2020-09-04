/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 17:49:04 by xtang             #+#    #+#             */
/*   Updated: 2020/09/04 17:49:12 by xtang            ###   ########.fr       */
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

void		*draw_julia_thread(void *temp)
{
	t_multi_th		*th;
	t_complex_plain	*plain;
	int				width;
	int				height;
	int				height_limit;

	th = temp;
	plain = (t_complex_plain *)malloc(sizeof(t_complex_plain));
	complex_plain_init(plain, th->fra, th->mouse);
	height = th->th_height;
	height_limit = th->th_height + (HEIGHT / THREAD_NB);
	while (height < height_limit)
	{
		width = 0;
		while (width < WIDTH)
		{
			julia_caculate(width, height, th->fra, plain);
			width++;
		}
		height++;
	}
	return (NULL);
}

void		draw_julia(t_fractal *fra, t_mouse *mouse)
{
	int			i;
	pthread_t	thread_id[THREAD_NB];
	t_multi_th	*th_id[THREAD_NB];

	i = -1;
	while (++i < THREAD_NB)
	{
		th_id[i] = (t_multi_th *)malloc(sizeof(t_multi_th));
		th_id[i]->mouse = mouse;
		th_id[i]->fra = fra;
		th_id[i]->th_height = i * (HEIGHT / THREAD_NB);
		pthread_create(&thread_id[i], NULL, draw_julia_thread, th_id[i]);
	}
	while (i--)
	{
		pthread_join(thread_id[i], NULL);
	}
}
