/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:37:58 by xtang             #+#    #+#             */
/*   Updated: 2020/09/30 17:38:02 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void		draw_flame(t_fractal *fra)
{
	int				samples;
	int				iteration;
	int 			max;
	double 			gamma;
	int 			color;
	int 			s_i;
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
	double			theta;
	double			theta2;
	int				temp;

	time_t t;
	t_complex_plain  *plain;
	t_flame_co	flame_co[NUM_F];
	t_f_pixel	**f_pixel;

	
	void  coeff_array_init()

	
	f_pixel = (t_f_pixel **)malloc(sizeof(t_f_pixel *) * HEIGHT);
	temp = 0;
	while ( temp < HEIGHT)
	{
		f_pixel[temp] = (t_f_pixel *)malloc (sizeof(t_f_pixel) * WIDTH);
		temp++;
	}

	plain = (t_complex_plain *)malloc(sizeof(t_complex_plain));

	plain->max.re = 1.777;
	plain->max.im = 1.0;
	plain->min.re = -1.777;
	plain->min.im = -1.0;

	iteration  = 1000;
	samples = 80000;

	srand((unsigned)time(&t));

	i = 0;
	while (i < NUM_F)
	{
		
		flame_co[i].a = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i].b = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i].c = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i].d = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i].e = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i].f = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i].pa1 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));
		flame_co[i].pa2 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));
		flame_co[i].pa3 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));
		flame_co[i].pa4 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));

		flame_co[i].red = 64 + rand() % (255 - 64);
		flame_co[i].green = 64 + rand() % (255 - 64);
		flame_co[i].blue = 64 + rand() % (255 - 64);
		i++;
	}

	s_i = 0;
	while (s_i < samples)
	{
		p_x = plain->min.re + 1.0 * rand() / RAND_MAX * (plain->max.re - plain->min.re);
		p_y = plain->min.im + 1.0 * rand() / RAND_MAX * (plain->max.im - plain->min.im);

		i_i = -20;
		while (i_i < iteration)
		{
			rand_f = rand() % NUM_F;

			x = flame_co[rand_f].a * p_x + flame_co[rand_f].b * p_y + flame_co[rand_f].c;
			y = flame_co[rand_f].d * p_x + flame_co[rand_f].e * p_y + flame_co[rand_f].f;
/*
			r = sqrt(x * x + y * y) * M_PI;
			theta = atan2(y, x) / M_PI;
			p_x = theta * sin (r);
			p_y = theta * cos (r);
*/
			r = sqrt (x * x + y * y);
			theta = atan2(y, x);
			p_x = (1.0 / r) * (cos (theta) + sin (r));
	      	p_y = (1.0 / r) * (sin (theta) - cos (r));

			if (i_i > 0)
			{
				theta2 = theta2 + ( 2 * M_PI);
				rot_x = p_x * cos(theta2) - p_y * sin (theta2);
				rot_y = p_x * sin(theta2) + p_y * cos (theta2);

				if (rot_x >= plain->min.re && rot_x <= plain->max.re
						&& rot_y >= plain->min.im && rot_x <= plain->max.im)
				{
					scr_x = WIDTH - (unsigned int) (((plain->max.re - rot_x) / (plain->max.re - plain->min.re) * WIDTH));
					scr_y = HEIGHT - (unsigned int) (((plain->max.im - rot_y) / (plain->max.im - plain->min.im) * HEIGHT));

					if ( f_pixel[scr_y][scr_x].counter == 0)
					{
						f_pixel[scr_y][scr_x].r = flame_co[rand_f].red;
						f_pixel[scr_y][scr_x].g = flame_co[rand_f].green;
						f_pixel[scr_y][scr_x].b = flame_co[rand_f].blue;
					}
					else
					{
						f_pixel[scr_y][scr_x].r = f_pixel[scr_y][scr_x].r + flame_co[rand_f].red / 2;
						f_pixel[scr_y][scr_x].g = f_pixel[scr_y][scr_x].g + flame_co[rand_f].green / 2;
						f_pixel[scr_y][scr_x].b = f_pixel[scr_y][scr_x].b + flame_co[rand_f].blue / 2;
					}
					f_pixel[scr_y][scr_x].counter++;
				}
			}
			i_i++;
		}
		s_i++;
	}

	max = 0;
	row = 0;
	while (row < HEIGHT)
	{
		col = 0;
		while (col < WIDTH)
		{
			if (f_pixel[row][col].counter != 0)
			{
				f_pixel[row][col].normal = (float) log10((double)f_pixel[row][col].counter);
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
			if (f_pixel[row][col].counter != 0)
			{
				f_pixel[row][col].normal /= max;
				f_pixel[row][col].r = (unsigned char) (float) (f_pixel[row][col].r) *  
						pow (f_pixel[row][col].normal, (1.0 /gamma));
				f_pixel[row][col].g = (unsigned char) (float) (f_pixel[row][col].g) *  
						pow (f_pixel[row][col].normal, (1.0 /gamma));
				f_pixel[row][col].b = (unsigned char) (float) (f_pixel[row][col].b) *  
						pow (f_pixel[row][col].normal, (1.0 /gamma));						
			} 
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
			if (f_pixel[row][col].counter != 0)
			{
				color = (f_pixel[row][col].r << 16 | f_pixel[row][col].g << 8 | f_pixel[row][col].b);

				draw_pixel(fra, row, col, color);				
					
			} 
			col++;
		}
		row++;
	}
}

