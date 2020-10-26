/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:37:58 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 11:48:41 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	plain_random_init(t_complex_plain *plain, t_flame_co *f_co)
{
	int		i;
	time_t	t;

	plain->max.re = 1.777;
	plain->max.im = 1.0;
	plain->min.re = -1.777;
	plain->min.im = -1.0;
	srand((unsigned)time(&t));
	i = 0;
	while (i < NUM_F)
	{
		f_co[i].a = -1.5 + drand48() * (1.5 - (-1.5));
		f_co[i].b = -1.5 + drand48() * (1.5 - (-1.5));
		f_co[i].c = -1.5 + drand48() * (1.5 - (-1.5));
		f_co[i].d = -1.5 + drand48() * (1.5 - (-1.5));
		f_co[i].e = -1.5 + drand48() * (1.5 - (-1.5));
		f_co[i].f = -1.5 + drand48() * (1.5 - (-1.5));
		f_co[i].red = (int)(drand48() * 256);
		f_co[i].green = (int)(drand48() * 256);
		f_co[i].blue = (int)(drand48() * 256);
		i++;
	}
}

void	variation_select_a(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r2;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	if (th->fra->flame_p == 0)
	{
		p->x = x;
		p->y = y;
	}
	else if (th->fra->flame_p == 1)
	{
		p->x = sin(x);
		p->y = sin(y);
	}
	else if (th->fra->flame_p == 2)
	{
		r2 = x * x + y * y;
		p->x = 1.0 / r2 * x;
		p->y = 1.0 / r2 * y;
	}
}

void	variation_select_b(t_multi_th *th, t_plane *p,\
											t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 3)
	{
		p->x = x * sin(x * x + y * y) - y * cos(x * x + y * y);
		p->y = x * cos(x * x + y * y) - y * sin(x * x + y * y);
	}
	else if (th->fra->flame_p == 4)
	{
		p->x = atan2(y, x) / M_PI;
		p->y = r - 1;
	}
	else if (th->fra->flame_p == 5)
	{
		p->x = r * sin(atan2(y, x) + r);
		p->y = r * cos(atan2(y, x) - r);
	}
}

void	variation_select_c(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 6)
	{
		p->x = r * sin(atan2(y, x) * r);
		p->y = -1 * r * cos(atan2(y, x) * r);
	}
	else if (th->fra->flame_p == 7)
	{
		p->x = atan2(y, x) / M_PI * sin(M_PI * r);
		p->y = atan2(y, x) / M_PI * cos(M_PI * r);
	}
	else if (th->fra->flame_p == 8)
	{
		p->x = 1 / r * (cos(atan2(y, x)) + sin(r));
		p->y = 1 / y * (sin(atan2(y, x)) - cos(r));
	}
}

void	variation_select_d(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 9)
	{
		p->x = sin(theta) / r;
		p->y = r * cos(theta);
	}
	else if (th->fra->flame_p == 10)
	{
		p->x = sin(theta) * cos(r);
		p->y = cos(theta) * sin(r);
	}
}

void	variation_select_e(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 11)
	{
		p->x = r * (sin(theta + r) * sin(theta + r) * sin(theta + r) +\
				cos(theta - r) * cos(theta - r) * cos(theta - r));
		p->y = r * (sin(theta + r) * sin(theta + r) * sin(theta + r) -\
				cos(theta - r) * cos(theta - r) * cos(theta - r));
	}
	else if (th->fra->flame_p == 12)
	{
		r = sqrt(x * x + y * y);
		theta = atan2(y, x);
		p->x = sqrt(r) * cos(theta / 2);
		p->y = sqrt(r) * sin(theta / 2);
	}
}

void	input_a(t_plane *p, double x, double y)
{
	p->x = x;
	p->y = y;
}

void	input_b(t_plane *p, double x, double y)
{
	p->x = 2.0 * x;
	p->y = y;
}

void	input_c(t_plane *p, double x, double y)
{
	p->x = x;
	p->y = y * 0.5;
}

void	input_d(t_plane *p, double x, double y)
{
	p->x = 2.0 * x;
	p->y = y * 0.5;
}

void	variation_select_f(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	if (th->fra->flame_p == 13)
	{
		if (x >= 0.0 && y >= 0.0)
			input_a(p, x, y);
		else if (x < 0.0 && y >= 0.0)
			input_b(p, x, y);
		else if (x >= 0.0 && y < 0.0)
			input_c(p, x, y);
		else if (x < 0.0 && y < 0.0)
			input_d(p, x, y);
	}
}

void	variation_select_g(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 14)
	{
		p->x = x + f_co[r_f].b * sin(y / (f_co[r_f].c * f_co[r_f].c));
		p->y = y + f_co[r_f].e * sin(x / (f_co[r_f].f * f_co[r_f].f));
	}
	else if (th->fra->flame_p == 15)
	{
		p->x = 2 / (r + 1) * y;
		p->y = 2 / (r + 1) * x;
	}
	else if (th->fra->flame_p == 16)
	{
		p->x = x + f_co[r_f].c * sin(tan(3 * y));
		p->y = y + f_co[r_f].f * sin(tan(3 * x));
	}
}

void	variation_select_h(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 17)
	{
		p->x = exp(x - 1) * cos(M_PI * y);
		p->y = exp(x - 1) * sin(M_PI * y);
	}
	else if (th->fra->flame_p == 18)
	{
		p->x = pow(r, sin(theta)) * cos(theta);
		p->y = pow(r, sin(theta)) * sin(theta);
	}
}

void	variation_select_i(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 19)
	{
		p->x = cos(M_PI * x) * cosh(y);
		p->y = -1 * sin(M_PI * x) * sinh(y);
	}
	else if (th->fra->flame_p == 20)
	{
		p->x = 2 / (r + 1) * x;
		p->y = 2 / (r + 1) * y;
	}
	else if (th->fra->flame_p == 21)
	{
		p->x = 4 / (x * x + y * y + 4) * x;
		p->y = 4 / (x * x + y * y + 4) * y;
	}
}

void	variation_select_j(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	if (th->fra->flame_p == 22)
	{
		p->x = sin(x);
		p->y = y;
	}
	else if (th->fra->flame_p == 23)
	{
		p->x = sin(x) / cos(y);
		p->y = tan(y);
	}
	else if (th->fra->flame_p == 24)
	{
		p->x = x / (x * x - y * y);
		p->y = y / (x * x - y * y);
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

int		pixel_log_density(t_f_pixel **f_pixel)
{
	int max;
	int row;
	int col;

	max = 0;
	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			if (f_pixel[row][col].counter != 0)
			{
				f_pixel[row][col].normal =\
							(float)log10((double)f_pixel[row][col].counter);
				if (f_pixel[row][col].normal > max)
				{
					max = f_pixel[row][col].normal;
				}
			}
			col++;
		}
		row++;
	}
	return (max);
}

void	pixel_gamma_factor(t_f_pixel **f_pixel, int max)
{
	int row;
	int col;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			f_pixel[row][col].normal /= max;
			f_pixel[row][col].r = (int)(f_pixel[row][col].r *\
									pow(f_pixel[row][col].normal, 1.0 / GAMMA));
			f_pixel[row][col].g = (int)(f_pixel[row][col].g *\
									pow(f_pixel[row][col].normal, 1.0 / GAMMA));
			f_pixel[row][col].b = (int)(f_pixel[row][col].b *\
									pow(f_pixel[row][col].normal, 1.0 / GAMMA));
			col++;
		}
		row++;
	}
}

void	rendering_flame(t_f_pixel **f_pixel, t_multi_th *th)
{
	int row;
	int col;
	int color;

	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			color = (f_pixel[row][col].r << 16\
					| f_pixel[row][col].g << 8 | f_pixel[row][col].b);
			draw_pixel(th->fra, col, row, color);
			col++;
		}
		row++;
	}
}

void	free_memory(t_f_pixel **f_pixel, t_complex_plain *plain)
{
	int	temp;

	free(plain);
	temp = 0;
	while (temp < HEIGHT)
	{
		free(f_pixel[temp]);
		temp++;
	}
	free(f_pixel);
}

void	*draw_flame_thread(void *th_temp)
{
	t_multi_th		*th;
	t_complex_plain	*plain;
	t_flame_co		f_co[NUM_F];
	t_f_pixel		**f_pixel;
	int				temp;

	th = th_temp;
	plain = (t_complex_plain *)malloc(sizeof(t_complex_plain));
	f_pixel = (t_f_pixel **)malloc(sizeof(t_f_pixel *) * HEIGHT);
	temp = 0;
	while (temp < HEIGHT)
	{
		f_pixel[temp] = (t_f_pixel *)malloc(sizeof(t_f_pixel) * WIDTH);
		temp++;
	}
	plain_random_init(plain, f_co);
	samples_init(th, plain, f_co, f_pixel);
	pixel_gamma_factor(f_pixel, pixel_log_density(f_pixel));
	rendering_flame(f_pixel, th);
	free_memory(f_pixel, plain);
	return (NULL);
}

void	flame_pattern(int key, t_combi *combi)
{
	if (key == MAIN_SPC)
		combi->fra->flame_p++;
	else if (key == MAIN_PLUS)
		combi->fra->flame_p++;
	else if (key == MAIN_MINUS)
		combi->fra->flame_p--;
	if (combi->fra->flame_p > 24)
		combi->fra->flame_p = 0;
	fractal_redraw(combi);
}

void	draw_flame(t_fractal *fra)
{
	int			i;
	pthread_t	thread_id[THREAD_NB];
	t_multi_th	*th_id[THREAD_NB];

	i = 0;
	while (i < THREAD_NB)
	{
		th_id[i] = (t_multi_th *)malloc(sizeof(t_multi_th));
		th_id[i]->th_sample = (int)(SAMPLES / THREAD_NB);
		th_id[i]->fra = fra;
		pthread_create(&thread_id[i], NULL, draw_flame_thread, th_id[i]);
		i++;
	}
	while (i--)
	{
		pthread_join(thread_id[i], NULL);
		free(th_id[i]);
	}
}
