/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:37:58 by xtang             #+#    #+#             */
/*   Updated: 2020/10/20 19:35:23 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void		draw_flame(t_fractal *fra)
{
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
	int				rand_f;
	double			r;
	double			r2;
	double			theta;
	double			theta2;
	int				temp;
	int				sym;
	int				symmetry;
	time_t			t;
	t_complex_plain	*plain;
	t_flame_co		flame_co[NUM_F];
	t_f_pixel		**f_pixel;
	double			p0;
	double			p1;

	symmetry = 1;
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
	iteration = 1000;
	samples = 50000;
	srand((unsigned)time(&t));
	i = 0;
	while (i < NUM_F)
	{
		flame_co[i].a = -1.5 + drand48() * (1.5 - (-1.5));
		flame_co[i].b = -1.5 + drand48() * (1.5 - (-1.5));
		flame_co[i].c = -1.5 + drand48() * (1.5 - (-1.5));
		flame_co[i].d = -1.5 + drand48() * (1.5 - (-1.5));
		flame_co[i].e = -1.5 + drand48() * (1.5 - (-1.5));
		flame_co[i].f = -1.5 + drand48() * (1.5 - (-1.5));
		flame_co[i].pa1 = -2.0 + drand48() * (2.0 - (-2.0));
		flame_co[i].pa2 = -2.0 + drand48() * (2.0 - (-2.0));
		flame_co[i].pa3 = -2.0 + drand48() * (2.0 - (-2.0));
		flame_co[i].pa4 = -2.0 + drand48() * (2.0 - (-2.0));
		flame_co[i].red = (int)(drand48() * 256);
		flame_co[i].green = (int)(drand48() * 256);
		flame_co[i].blue = (int)(drand48() * 256);
		i++;
	}
/*
**	i = 0;
**	while (i < NUM_F)
**	{
**		printf("%d :", i);
**		printf("%f, %f, %f, %f, %f, %f, %d, %d, %d\n",
**			flame_co[i].a,flame_co[i].b,flame_co[i].c,
**			flame_co[i].d,flame_co[i].e,flame_co[i].f,
**			flame_co[i].red, flame_co[i].green, flame_co[i].blue);
**		i++;
**	}
*/
	s_i = 0;
	while (s_i < samples)
	{
		p_x = plain->min.re + drand48() * (plain->max.re - plain->min.re);
		p_y = plain->min.im + drand48() * (plain->max.im - plain->min.im);
		i_i = -20;
		while (i_i < iteration)
		{
			rand_f = rand() % NUM_F;
			x = flame_co[rand_f].a * p_x + flame_co[rand_f].b * p_y + flame_co[rand_f].c;
			y = flame_co[rand_f].d * p_x + flame_co[rand_f].e * p_y + flame_co[rand_f].f;
			if (fra->flame_p == 0)
			{
				// Variation 0: Linear
				p_x = x;
				p_y = y;
			}
			else if (fra->flame_p == 1)
			{
				// Variation 1: Sinusoidal
				p_x = sin(x);
				p_y = sin(y);
			}
			else if (fra->flame_p == 2)
			{
				// Variation 2: Spherical
				r2 = x * x + y * y;
				p_x = 1.0 / r2 * x;
				p_y = 1.0 / r2 * y;
			}
			else if (fra->flame_p == 3)
			{
				// Variation 3: Swirl
				r2 = x * x + y * y;
				p_x = x * sin(r2) - y * cos(r2);
				p_y = x * cos(r2) - y * sin(r2);
			}
			else if (fra->flame_p == 4)
			{
				// Variation 4: Horseshoe
				r = 1.0 / sqrt(x * x + y * y);
				p_x = r * (x - y) * (x + y);
				p_y = r * 2.0 * x * y;
			}
			else if (fra->flame_p == 5)
			{
				// Variation 5: Polar
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = theta / M_PI;
				p_y = r - 1;
			}
			else if (fra->flame_p == 6)
			{
				// Variation 6: Handkerchief
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = r * sin(theta + r);
				p_y = r * cos(theta - r);
			}
			else if (fra->flame_p == 7)
			{
				// Variation 7: Heart
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = r * sin(theta * r);
				p_y = -1 * r * cos(theta * r);
			}
			else if (fra->flame_p == 8)
			{
				// Variation 8: Disc
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = theta / M_PI * sin(M_PI * r);
				p_y = theta / M_PI * cos(M_PI * r);
			}
			else if (fra->flame_p == 9)
			{
				// Variation 9: Spiral
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = 1 / r * (cos(theta) + sin(r));
				p_x = 1 / y * (sin(theta) - cos(r));
			}
			else if (fra->flame_p == 10)
			{
				// Variation 10: Hyperbolic
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = sin(theta) / r;
				p_y = r * cos(theta);
			}
			else if (fra->flame_p == 11)
			{
				// Variation 11: Diamond
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = sin(theta) * cos(r);
				p_y = cos(theta) * sin(r);
			}
			else if (fra->flame_p == 12)
			{
				// Variation 12: Ex
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p0 = sin(theta + r);
				p1 = cos(theta - r);
				p_x = r * (p0 * p0 * p0 + p1 * p1 * p1);
				p_y = r * (p0 * p0 * p0 - p1 * p1 * p1);
			}
			else if (fra->flame_p == 13)
			{
				// Variation 13: Julia
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = sqrt(r) * cos(theta / 2);
				p_y = sqrt(r) * sin(theta / 2);
			}
			else if (fra->flame_p == 14)
			{
				// Variation 14: Bent
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
					p_y = y / 2.0;
				}
				else if (x < 0.0 && y < 0.0)
				{
					p_x = 2.0 * x;
					p_y = y / 2.0;
				}
			}
			else if (fra->flame_p == 15)
			{
				// Variation 15: Waves
				p_x = x + flame_co[rand_f].b * sin(y / (flame_co[rand_f].c * flame_co[rand_f].c));
				p_y = y + flame_co[rand_f].e * sin(y / (flame_co[rand_f].f * flame_co[rand_f].f));
			}
			else if (fra->flame_p == 16)
			{
				// Variation 16: Fisheye
				r = sqrt(x * x + y * y);
				p_x = 2 / (r + 1) * y;
				p_y = 2 / (r + 1) * x;
			}
			else if (fra->flame_p == 17)
			{
				// Variation 17: Popcorn
				p_x = x + flame_co[rand_f].c * sin(tan(3 * y));
				p_y = y + flame_co[rand_f].f * sin(tan(3 * x));
			}
			else if (fra->flame_p == 18)
			{
				// Variation 18: Exponential
				p_x = exp(x - 1) * cos(M_PI * y);
				p_y = exp(x - 1) * sin(M_PI * y);
			}
			else if (fra->flame_p == 19)
			{
				// Variation 19: Power
				r = sqrt(x * x + y * y);
				theta = atan2(y, x);
				p_x = pow(r, sin(theta)) * cos(theta);
				p_y = pow(r, sin(theta)) * sin(theta);
			}
			else if (fra->flame_p == 20)
			{
				// Variation 20: Cosine
				p_x = cos(M_PI * x) * cosh(y);
				p_y = -1 * sin(M_PI * x) * sinh(y);
			}
			else if (fra->flame_p == 21)
			{
				// Variation 27: Eyefish
				r = sqrt(x * x + y * y);
				p_x = 2 / (r + 1) * x;
				p_y = 2 / (r + 1) * y;
			}
			else if (fra->flame_p == 22)
			{
				// Variation 28: Bubble
				r2 = x * x + y * y;
				p_x = 4 / (r2 + 4) * x;
				p_y = 4 / (r2 + 4) * y;
			}
			else if (fra->flame_p == 23)
			{
				// Variation 29: Cylinder
				p_x = sin(x);
				p_y = y;
			}
			else if (fra->flame_p == 24)
			{
				// Variation 42: Tangent
				p_x = sin(x) / cos(y);
				p_y = tan(y);
			}
			else if (fra->flame_p == 25)
			{
				// Variation 48: Cross
				p_x = x / (x * x - y * y);
				p_y = y / (x * x - y * y);
			}
			if (i_i > 0)
			{
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
								f_pixel[scr_y][scr_x].r = flame_co[rand_f].red;
								f_pixel[scr_y][scr_x].g = flame_co[rand_f].green;
								f_pixel[scr_y][scr_x].b = flame_co[rand_f].blue;
							}
							else
							{
								f_pixel[scr_y][scr_x].r = (f_pixel[scr_y][scr_x].r + flame_co[rand_f].red) / 2;
								f_pixel[scr_y][scr_x].g = (f_pixel[scr_y][scr_x].g + flame_co[rand_f].green) / 2;
								f_pixel[scr_y][scr_x].b = (f_pixel[scr_y][scr_x].b + flame_co[rand_f].blue) / 2;
							}
							f_pixel[scr_y][scr_x].counter++;
						}
					}
					sym++;
				}
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
	col = 0;
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
	col = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			color = (f_pixel[row][col].r << 16 | f_pixel[row][col].g << 8 | f_pixel[row][col].b);
			draw_pixel(fra, col, row, color);
			col++;
		}
		row++;
	}
}

void	flame_pattern(int key, t_combi *combi)
{
	if (key == 49)
	{
		combi->fra->flame_p++;
		if (combi->fra->flame_p > 25)
			combi->fra->flame_p = 0;
		fractal_redraw(combi);
	}
}
