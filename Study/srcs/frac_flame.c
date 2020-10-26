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

void	variation_select_a(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r2;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	if (th->fra->flame_p == 0)
	{
		*p_x = x;
		*p_y = y;
	}
	else if (th->fra->flame_p == 1)
	{
		*p_x = sin(x);
		*p_y = sin(y);
	}
	else if (th->fra->flame_p == 2)
	{
		r2 = x * x + y * y;
		*p_x = 1.0 / r2 * x;
		*p_y = 1.0 / r2 * y;
	}
}

void	variation_select_b(t_multi_th *th, double *p_x, double *p_y,\
											t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 3)
	{
		*p_x = x * sin(x * x + y * y) - y * cos(x * x + y * y);
		*p_y = x * cos(x * x + y * y) - y * sin(x * x + y * y);
	}
	else if (th->fra->flame_p == 4)
	{
		*p_x = atan2(y, x) / M_PI;
		*p_y = r - 1;
	}
	else if (th->fra->flame_p == 5)
	{
		*p_x = r * sin(atan2(y, x) + r);
		*p_y = r * cos(atan2(y, x) - r);
	}
}

void	variation_select_c(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 6)
	{
		*p_x = r * sin(atan2(y, x) * r);
		*p_y = -1 * r * cos(atan2(y, x) * r);
	}
	else if (th->fra->flame_p == 7)
	{
		*p_x = atan2(y, x) / M_PI * sin(M_PI * r);
		*p_y = atan2(y, x) / M_PI * cos(M_PI * r);
	}
	else if (th->fra->flame_p == 8)
	{
		*p_x = 1 / r * (cos(atan2(y, x)) + sin(r));
		*p_y = 1 / y * (sin(atan2(y, x)) - cos(r));
	}
}

void	variation_select_d(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 9)
	{
		*p_x = sin(theta) / r;
		*p_y = r * cos(theta);
	}
	else if (th->fra->flame_p == 10)
	{
		*p_x = sin(theta) * cos(r);
		*p_y = cos(theta) * sin(r);
	}
}

void	variation_select_e(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 11)
	{
		*p_x = r * (sin(theta + r) * sin(theta + r) * sin(theta + r) +\
				cos(theta - r) * cos(theta - r) * cos(theta - r));
		*p_y = r * (sin(theta + r) * sin(theta + r) * sin(theta + r) -\
				cos(theta - r) * cos(theta - r) * cos(theta - r));
	}
	else if (th->fra->flame_p == 12)
	{
		r = sqrt(x * x + y * y);
		theta = atan2(y, x);
		*p_x = sqrt(r) * cos(theta / 2);
		*p_y = sqrt(r) * sin(theta / 2);
	}
}

void	input_a(double *p_x, double *p_y, double x, double y)
{
	*p_x = x;
	*p_y = y;
}

void	input_b(double *p_x, double *p_y, double x, double y)
{
	*p_x = 2.0 * x;
	*p_y = y;
}

void	input_c(double *p_x, double *p_y, double x, double y)
{
	*p_x = x;
	*p_y = y * 0.5;
}

void	input_d(double *p_x, double *p_y, double x, double y)
{
	*p_x = 2.0 * x;
	*p_y = y * 0.5;
}

void	variation_select_f(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	if (th->fra->flame_p == 13)
	{
		if (x >= 0.0 && y >= 0.0)
			input_a(p_x, p_y, x, y);
		else if (x < 0.0 && y >= 0.0)
			input_b(p_x, p_y, x, y);
		else if (x >= 0.0 && y < 0.0)
			input_c(p_x, p_y, x, y);
		else if (x < 0.0 && y < 0.0)
			input_d(p_x, p_y, x, y);
	}
}

void	variation_select_g(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 14)
	{
		*p_x = x + f_co[r_f].b * sin(y / (f_co[r_f].c * f_co[r_f].c));
		*p_y = y + f_co[r_f].e * sin(x / (f_co[r_f].f * f_co[r_f].f));
	}
	else if (th->fra->flame_p == 15)
	{
		*p_x = 2 / (r + 1) * y;
		*p_y = 2 / (r + 1) * x;
	}
	else if (th->fra->flame_p == 16)
	{
		*p_x = x + f_co[r_f].c * sin(tan(3 * y));
		*p_y = y + f_co[r_f].f * sin(tan(3 * x));
	}
}

void	variation_select_h(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 17)
	{
		*p_x = exp(x - 1) * cos(M_PI * y);
		*p_y = exp(x - 1) * sin(M_PI * y);
	}
	else if (th->fra->flame_p == 18)
	{
		*p_x = pow(r, sin(theta)) * cos(theta);
		*p_y = pow(r, sin(theta)) * sin(theta);
	}
}

void	variation_select_i(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 19)
	{
		*p_x = cos(M_PI * x) * cosh(y);
		*p_y = -1 * sin(M_PI * x) * sinh(y);
	}
	else if (th->fra->flame_p == 20)
	{
		*p_x = 2 / (r + 1) * x;
		*p_y = 2 / (r + 1) * y;
	}
	else if (th->fra->flame_p == 21)
	{
		*p_x = 4 / (x * x + y * y + 4) * x;
		*p_y = 4 / (x * x + y * y + 4) * y;
	}
}

void	variation_select_j(t_multi_th *th, double *p_x, double *p_y,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;

	x = f_co[r_f].a * (*p_x) + f_co[r_f].b * (*p_y) + f_co[r_f].c;
	y = f_co[r_f].d * (*p_x) + f_co[r_f].e * (*p_y) + f_co[r_f].f;
	if (th->fra->flame_p == 22)
	{
		*p_x = sin(x);
		*p_y = y;
	}
	else if (th->fra->flame_p == 23)
	{
		*p_x = sin(x) / cos(y);
		*p_y = tan(y);
	}
	else if (th->fra->flame_p == 24)
	{
		*p_x = x / (x * x - y * y);
		*p_y = y / (x * x - y * y);
	}
}

void	samples_iteration_select(double *p_x, double *p_y, t_multi_th *th,\
													t_flame_co *f_co, int r_f)
{
	if (th->fra->flame_p >= 0 && th->fra->flame_p <= 2)
		variation_select_a(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 3 && th->fra->flame_p <= 5)
		variation_select_b(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 6 && th->fra->flame_p <= 8)
		variation_select_c(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 9 && th->fra->flame_p <= 10)
		variation_select_d(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 11 && th->fra->flame_p <= 12)
		variation_select_e(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p == 13)
		variation_select_f(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 14 && th->fra->flame_p <= 16)
		variation_select_g(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 17 && th->fra->flame_p <= 18)
		variation_select_h(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 19 && th->fra->flame_p <= 21)
		variation_select_i(th, p_x, p_y, f_co, r_f);
	else if (th->fra->flame_p >= 22 && th->fra->flame_p <= 24)
		variation_select_j(th, p_x, p_y, f_co, r_f);
}

void	samples_symmetry(double p_x, double p_y, t_complex_plain *plain,\
									t_f_pixel **f_pixel, t_flame_co *f_co, int r_f)
{
	int		sym;
	double	theta2;
	double	rot_x;
	double	rot_y;
	int		scr_x;
	int		scr_y;

	sym = 0;
	theta2 = 0.0;
	while (sym < SYMMETRY)
	{
		theta2 = theta2 + (2 * M_PI) / SYMMETRY;
		rot_x = p_x * cos(theta2) - p_y * sin(theta2);
		rot_y = p_x * sin(theta2) + p_y * cos(theta2);
		if (rot_x >= plain->min.re && rot_x <= plain->max.re
				&& rot_y >= plain->min.im && rot_y <= plain->max.im)
		{
			scr_x = WIDTH - (unsigned int)(((plain->max.re - rot_x) / (plain->max.re - plain->min.re) * WIDTH));
			scr_y = HEIGHT - (unsigned int)(((plain->max.im - rot_y) / (plain->max.im - plain->min.im) * HEIGHT));
			if (scr_x >= 0 && scr_x < WIDTH && scr_y >= 0 && scr_y < HEIGHT)
			{
				if (f_pixel[scr_y][scr_x].counter == 0)
				{
					f_pixel[scr_y][scr_x].r = f_co[r_f].red;
					f_pixel[scr_y][scr_x].g = f_co[r_f].green;
					f_pixel[scr_y][scr_x].b = f_co[r_f].blue;
				}
				else
				{
					f_pixel[scr_y][scr_x].r = (f_pixel[scr_y][scr_x].r + f_co[r_f].red) / 2;
					f_pixel[scr_y][scr_x].g = (f_pixel[scr_y][scr_x].g + f_co[r_f].green) / 2;
					f_pixel[scr_y][scr_x].b = (f_pixel[scr_y][scr_x].b + f_co[r_f].blue) / 2;
				}
				f_pixel[scr_y][scr_x].counter++;
			}
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
	double	p_x;
	double	p_y;
	int		r_d;

	samples = th->th_sample;
	s_i = -20;
	while (s_i < samples)
	{
		p_x = plain->min.re + drand48() * (plain->max.re - plain->min.re);
		p_y = plain->min.im + drand48() * (plain->max.im - plain->min.im);
		i_i = 0;
		while (i_i < FLAME_ITERATE)
		{
			r_d = rand() % NUM_F;
			samples_iteration_select(&p_x, &p_y, th, f_co, r_d);
			samples_symmetry(p_x, p_y, plain, f_pixel, f_co, r_d);
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
				f_pixel[row][col].normal = (float)log10((double)f_pixel[row][col].counter);
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
			f_pixel[row][col].r = (int)(f_pixel[row][col].r * pow(f_pixel[row][col].normal, 1.0 / GAMMA));
			f_pixel[row][col].g = (int)(f_pixel[row][col].g * pow(f_pixel[row][col].normal, 1.0 / GAMMA));
			f_pixel[row][col].b = (int)(f_pixel[row][col].b * pow(f_pixel[row][col].normal, 1.0 / GAMMA));
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
			color = (f_pixel[row][col].r << 16 | f_pixel[row][col].g << 8 | f_pixel[row][col].b);
			draw_pixel(th->fra, col, row, color);
			col++;
		}
		row++;
	}
}

void	*draw_flame_thread(void *th_temp)
{
	t_multi_th		*th;
	t_complex_plain	*plain;
	t_flame_co		f_co[NUM_F];
	t_f_pixel		**f_pixel;
	int				temp;
	int				max;

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
	max = pixel_log_density(f_pixel);
	pixel_gamma_factor(f_pixel, max);
	rendering_flame(f_pixel, th);
	free(plain);
	temp = 0;
	while (temp < HEIGHT)
	{
		free(f_pixel[temp]);
		temp++;
	}
	free(f_pixel);
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
