/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:37:58 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 11:48:41 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	src_to_pixel(t_scr scr, t_f_pixel **f_pixel, t_flame_co *f_co, int rnd)
{
	if (scr.x >= 0 && scr.x < WIDTH && scr.y >= 0 && scr.y < HEIGHT)
	{
		if (f_pixel[scr.y][scr.x].counter == 0)
		{
			f_pixel[scr.y][scr.x].r = f_co[rnd].red;
			f_pixel[scr.y][scr.x].g = f_co[rnd].green;
			f_pixel[scr.y][scr.x].b = f_co[rnd].blue;
		}
		else
		{
			f_pixel[scr.y][scr.x].r =\
							(f_pixel[scr.y][scr.x].r + f_co[rnd].red) / 2;
			f_pixel[scr.y][scr.x].g =\
							(f_pixel[scr.y][scr.x].g + f_co[rnd].green) / 2;
			f_pixel[scr.y][scr.x].b =\
							(f_pixel[scr.y][scr.x].b + f_co[rnd].blue) / 2;
		}
		f_pixel[scr.y][scr.x].counter++;
	}
}

void	samples_symmetry(t_plane p, t_complex_plain *plain,\
									t_f_pixel **f_pixel, t_flame_co *f_co)
{
	int		sym;
	double	theta2;
	t_plane	rot;
	t_scr	scr;
	int		rnd;

	rnd = f_co[0].rand;
	sym = 0;
	theta2 = 0.0;
	while (sym < SYMMETRY)
	{
		theta2 = theta2 + (2 * M_PI) / SYMMETRY;
		rot.x = p.x * cos(theta2) - p.y * sin(theta2);
		rot.y = p.x * sin(theta2) + p.y * cos(theta2);
		if (rot.x >= plain->min.re && rot.x <= plain->max.re
				&& rot.y >= plain->min.im && rot.y <= plain->max.im)
		{
			scr.x = WIDTH - (unsigned int)(((plain->max.re - rot.x) /\
								(plain->max.re - plain->min.re) * WIDTH));
			scr.y = HEIGHT - (unsigned int)(((plain->max.im - rot.y) /\
								(plain->max.im - plain->min.im) * HEIGHT));
			src_to_pixel(scr, f_pixel, f_co, rnd);
		}
		sym++;
	}
}

void	samples_iteration_select(t_plane *p, t_multi_th *th,\
													t_flame_co *f_co)
{
	if (th->fra->flame_p >= 0 && th->fra->flame_p <= 2)
		variation_select_a(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 3 && th->fra->flame_p <= 5)
		variation_select_b(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 6 && th->fra->flame_p <= 8)
		variation_select_c(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 9 && th->fra->flame_p <= 10)
		variation_select_d(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 11 && th->fra->flame_p <= 12)
		variation_select_e(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p == 13)
		variation_select_f(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 14 && th->fra->flame_p <= 16)
		variation_select_g(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 17 && th->fra->flame_p <= 18)
		variation_select_h(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 19 && th->fra->flame_p <= 21)
		variation_select_i(th, p, f_co, f_co[0].rand);
	else if (th->fra->flame_p >= 22 && th->fra->flame_p <= 24)
		variation_select_j(th, p, f_co, f_co[0].rand);
}

void	samples_init(t_multi_th *th, t_complex_plain *plain,\
								t_flame_co *f_co, t_f_pixel **f_pixel)
{
	int		s_i;
	int		i_i;
	int		samples;
	t_plane	p;

	samples = th->th_sample;
	s_i = -20;
	while (s_i < samples)
	{
		p.x = plain->min.re + drand48() * (plain->max.re - plain->min.re);
		p.y = plain->min.im + drand48() * (plain->max.im - plain->min.im);
		i_i = 0;
		while (i_i < FLAME_ITERATE)
		{
			f_co[0].rand = rand() % NUM_F;
			samples_iteration_select(&p, th, f_co);
			samples_symmetry(p, plain, f_pixel, f_co);
			i_i++;
		}
		s_i++;
	}
}
