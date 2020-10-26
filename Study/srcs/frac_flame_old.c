/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:37:58 by xtang             #+#    #+#             */
/*   Updated: 2020/10/21 16:46:50 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	*draw_flame_thread(void *th_temp)
{
	t_multi_th		*th;
	int				samples;
	int				iteration;
	int				max;
	double			gamma;
	int				color;
	int				s_i;
	int				i_i;
	double			p_x;
	double			p_y;
	double			x;
	double			y;
	double			rot_x;
	double			rot_y;
	int				scr_x;
	int				scr_y;
	int				row;
	int				col;
	int				i;
	int				r_f;
	double			r;
	double			r2;
	double			theta;
	double			theta2;
	int				temp;
	int				sym;
	int				symmetry;
	time_t			t;
	t_complex_plain	*plain;
	t_flame_co		f_co[NUM_F];
	t_f_pixel		**f_pixel;
	double			p0;
	double			p1;
	int				free_height;

	th = th_temp;
	symmetry = 2;
	f_pixel = (t_f_pixel **)malloc(sizeof(t_f_pixel *) * HEIGHT);
	temp = 0;
	while (temp < HEIGHT)
	{
		f_pixel[temp] = (t_f_pixel *)malloc(sizeof(t_f_pixel) * WIDTH);
		temp++;
	}
	plain = (t_complex_plain *)malloc(sizeof(t_complex_plain));
	plain->max.re = 1.777;
	plain->max.im = 1.0;
	plain->min.re = -1.777;
	plain->min.im = -1.0;
	iteration = 1500;
	samples = th->th_sample;
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
	int debug;
	debug = 0;
	while(debug < NUM_F)
	{
		printf("f_co[%d].a = %f \n ", debug, f_co[debug].a);
		printf("f_co[%d].b = %f \n ", debug, f_co[debug].b);
		printf("f_co[%d].c = %f \n ", debug, f_co[debug].c);
		printf("f_co[%d].d = %f \n ", debug, f_co[debug].d);
		printf("f_co[%d].e = %f \n ", debug, f_co[debug].e);
		printf("f_co[%d].f = %f \n ", debug, f_co[debug].f);
		printf("f_co[%d].red = %d \n ", debug, f_co[debug].red);
		printf("f_co[%d].green = %d \n ", debug, f_co[debug].green);
		printf("f_co[%d].blue = %d \n ", debug, f_co[debug].blue);
		printf("\n");
		debug++;
	}

	s_i = -20;
	while (s_i < samples)
	{
		p_x = plain->min.re + drand48() * (plain->max.re - plain->min.re);
		p_y = plain->min.im + drand48() * (plain->max.im - plain->min.im);
		i_i = 0;
		while (i_i < iteration)
		{
			r_f = rand() % NUM_F;
			x = f_co[r_f].a * p_x + f_co[r_f].b * p_y + f_co[r_f].c;
			y = f_co[r_f].d * p_x + f_co[r_f].e * p_y + f_co[r_f].f;
			if (th->fra->flame_p == 0)
			{
				p_x = x;
				p_y = y;
			}
			else if (th->fra->flame_p == 1)
			{
				p_x = sin(x);
				p_y = sin(y);
			}
			else if (th->fra->flame_p == 2)
			{
				r2 = x * x + y * y;
				p_x = 1.0 / r2 * x;
				p_y = 1.0 / r2 * y;
			}
			else if (th->fra->flame_p == 3)
			{
				r2 = x * x + y * y;
				p_x = x * sin(r2) - y * cos(r2);
				p_y = x * cos(r2) - y * sin(r2);
			}
			else if (th->fra->flame_p == 4)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = theta / M_PI;
				p_y = r - 1;
			}
			else if (th->fra->flame_p == 5)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = r * sin(theta + r);
				p_y = r * cos(theta - r);
			}
			else if (th->fra->flame_p == 6)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = r * sin(theta * r);
				p_y = -1 * r * cos(theta * r);
			}
			else if (th->fra->flame_p == 7)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = theta / M_PI * sin(M_PI * r);
				p_y = theta / M_PI * cos(M_PI * r);
			}
			else if (th->fra->flame_p == 8)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = 1 / r * (cos(theta) + sin(r));
				p_y = 1 / y * (sin(theta) - cos(r));
			}
			else if (th->fra->flame_p == 9)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = sin(theta) / r;
				p_y = r * cos(theta);
			}
			else if (th->fra->flame_p == 10)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = sin(theta) * cos(r);
				p_y = cos(theta) * sin(r);
			}
			else if (th->fra->flame_p == 11)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p0 = sin(theta + r);
				p1 = cos(theta - r);
				p_x = r * (p0 * p0 * p0 + p1 * p1 * p1);
				p_y = r * (p0 * p0 * p0 - p1 * p1 * p1);
			}
			else if (th->fra->flame_p == 12)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = sqrt(r) * cos(theta / 2);
				p_y = sqrt(r) * sin(theta / 2);
			}
			else if (th->fra->flame_p == 13)
			{
				if (x >= 0.0 && y >= 0.0)
				{
					p_x = x;
					p_y = y;
				}
				else if (x < 0.0 && y >= 0.0)
				{
					p_x = 2.0 * x;
					p_y = y;
				}
				else if (x >= 0.0 && y < 0.0)
				{
					p_x = x;
					p_y = y * 0.5;
				}
				else if (x < 0.0 && y < 0.0)
				{
					p_x = 2.0 * x;
					p_y = y * 0.5;
				}
			}
			else if (th->fra->flame_p == 14)
			{
				p_x = x + f_co[r_f].b * sin(y / (f_co[r_f].c * f_co[r_f].c));
				p_y = y + f_co[r_f].e * sin(x / (f_co[r_f].f * f_co[r_f].f));
			}
			else if (th->fra->flame_p == 15)
			{
				r = sqrt(x * x + y * y);
				p_x = 2 / (r + 1) * y;
				p_y = 2 / (r + 1) * x;
			}
			else if (th->fra->flame_p == 16)
			{
				p_x = x + f_co[r_f].c * sin(tan(3 * y));
				p_y = y + f_co[r_f].f * sin(tan(3 * x));
			}
			else if (th->fra->flame_p == 17)
			{
				p_x = exp(x - 1) * cos(M_PI * y);
				p_y = exp(x - 1) * sin(M_PI * y);
			}
			else if (th->fra->flame_p == 18)
			{
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = pow(r, sin(theta)) * cos(theta);
				p_y = pow(r, sin(theta)) * sin(theta);
			}
			else if (th->fra->flame_p == 19)
			{
				p_x = cos(M_PI * x) * cosh(y);
				p_y = -1 * sin(M_PI * x) * sinh(y);
			}
			else if (th->fra->flame_p == 20)
			{
				r = sqrt(x * x + y * y);
				p_x = 2 / (r + 1) * x;
				p_y = 2 / (r + 1) * y;
			}
			else if (th->fra->flame_p == 21)
			{
				r2 = x * x + y * y;
				p_x = 4 / (r2 + 4) * x;
				p_y = 4 / (r2 + 4) * y;
			}
			else if (th->fra->flame_p == 22)
			{
				p_x = sin(x);
				p_y = y;
			}
			else if (th->fra->flame_p == 23)
			{
				p_x = sin(x) / cos(y);
				p_y = tan(y);
			}
			else if (th->fra->flame_p == 24)
			{
				p_x = x / (x * x - y * y);
				p_y = y / (x * x - y * y);
			}
			
			theta2 = 0.0;
			sym = 0;
			while (sym < symmetry)
			{
				theta2 = theta2 + (2 * M_PI) / symmetry;
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
			i_i++;
		}
		s_i++;
	}
	max = 0;
	row = 0;
	col = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			if (f_pixel[row][col].counter != 0)
			{
				f_pixel[row][col].normal = (float)log10((double)f_pixel[row][col].counter);
				if (f_pixel[row][col].normal > max)
					max = f_pixel[row][col].normal;
			}
			col++;
		}
		row++;
	}
	gamma = 2.2;
	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			f_pixel[row][col].normal /= max;
			f_pixel[row][col].r = (int)(f_pixel[row][col].r * pow(f_pixel[row][col].normal, 1.0 / gamma));
			f_pixel[row][col].g = (int)(f_pixel[row][col].g * pow(f_pixel[row][col].normal, 1.0 / gamma));
			f_pixel[row][col].b = (int)(f_pixel[row][col].b * pow(f_pixel[row][col].normal, 1.0 / gamma));
			col++;
		}
		row++;
	}
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
	free(plain);
	free_height = 0;
	while (free_height < HEIGHT)
	{
		free(f_pixel[free_height]);
		free_height++;
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
