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
/*
static void	julia_caculate(int width, int height, t_fractal *fra,\
								t_complex_plain *plain)
{
	int			i;
	t_complex	c;
	t_complex	new;
	t_complex	old;
	int			color;

	c.re = -0.882 + plain->offset.re;
	c.im = 0.253 + plain->offset.im;
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
	color = assign_color(new.re, new.im, i, fra);
	draw_pixel(fra, width, height, color);
}

static void	complex_plain_init(t_complex_plain *plain, t_fractal *fra,\
					t_mouse *mouse)
{
	plain->min.re = -1.6;
	plain->max.re = 1.6;
	plain->min.im = -1.08;
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
	free(plain);
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
		free(th_id[i]);
	}
}
*/
/*
void		draw_flame(t_fractal *fra)
{	
	
	int a_x;
	int a_y;
	int b_x;
	int b_y;
	int c_x;
	int c_y;
	int x;
	int y;

	int r;

	int i;
	int color;
	time_t t;

	i = 0;
	srand((unsigned) time(&t));
	color = 0x87CEEB;

	a_x = WIDTH / 2;
	a_y = 0;
	b_x = 0;
	b_y = HEIGHT;
	c_x = WIDTH;
	c_y = HEIGHT;

	x = rand() % 1920;
	y = rand() % 1280;
*/


/*
	a_x = rand() % 1920;
	a_y = rand() % 1280;
	b_x = rand() % 1920;
	b_y = rand() % 1280;
	c_x = rand() % 1920;
	c_y = rand() % 1280;

	x = rand() % 1920;
	y = rand() % 1280;

	while( i < 10000)
	{
		x = rand() % 1920;
		y = rand() % 1280;
		draw_pixel(fra, x, y, color);
		i++;
	}
*/
/*
	while (i < 100000)
	{
		r = rand() % 3;
		if (r == 0)
		{
			x = (x + a_x) / 2;
			y = (y + a_y) / 2;
			draw_pixel(fra, x, y, 0xFFFF00);
		}
		else if (r == 1)
		{
			x = (x + b_x) / 2;
			y = (y + b_y) / 2;
			draw_pixel(fra, x, y, 0x7CFC00);	
		}
		else
		{
			x = (x + c_x) / 2;
			y = (y + c_y) / 2;
			draw_pixel(fra, x, y, 0xFF4500);
		}
		i++;
	}
}
*/
/*
void		draw_flame(t_fractal *fra)
{	
	int c_x;
	int c_y;

	int n_x;
	int n_y;

//	int p_x;
//	int p_y;

	int s_x[SEED];
	int s_y[SEED];

	int i;
	int j;
	time_t t;
	int r;
	float present;
	float angle;
	int		len;

	present = 0.58;
	srand((unsigned) time(&t));

	c_x = WIDTH /2;
	c_y = HEIGHT /2;

	len = (int)(HEIGHT / 2 * 0.60); 

	j = 0;
	while (j < SEED)
	{
		angle = j * 2 * PI / SEED;
		s_x[j] = WIDTH / 2 + len * cos(angle);
		s_y[j] = HEIGHT / 2 + len * sin(angle);
		draw_pixel(fra, s_x[j], s_y[j], 0xFF4500);
		j++;
	}


	i = 0;
	while (i < 100000)
	{
		r = rand() % SEED;
		n_x = s_x[r];
		n_y = s_y[r];
//		if (n_x != p_x && n_y != p_y)
//		{
			c_x = c_x + (n_x - c_x) * present;
			c_y = c_y + (n_y - c_y) * present;
			draw_pixel(fra, c_x, c_y, 0xFFFF00);
//		}
//		p_x = n_x;
//		p_y = n_y;
		i++;
	}
}
*/

void		draw_flame(t_fractal *fra)
{
	time_t t;
	int samples;
	int s_i;
	t_complex_plain  *plain;
	double p_x;
	double p_y;
	double x;
	double y;
	double rot_x;
	double rot_y;
	int		scr_x;
	int		scr_y;
	int	i_i;
	int iteration;
	t_flame_co	*flame_co[NUM_F];
	t_f_pixel	f_pixel[HEIGHT][WIDTH];

	int row;
	int col;

	int i ;
	int rand_f;
	double r;
	double theta;
	double theta2;
	int max;
	double gamma;
	int color;
	
	
	plain = (t_complex_plain *)malloc(sizeof(t_complex_plain));
	plain->max.re = 1.777;
	plain->max.im = 1.0;
	plain->min.re = -1.777;
	plain->min.im = -1.0;

	iteration  = 1000;
	samples = 20000;

	srand((unsigned)time(&t));

	i = 0;
	while (i < NUM_F)
	{
		flame_co[i] = (t_flame_co *)malloc(sizeof(t_flame_co));
		flame_co[i]->a = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i]->b = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i]->c = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i]->d = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i]->e = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i]->f = -1.5 + 1.0 * rand() / RAND_MAX * ( 1.5 - (-1.5));
		flame_co[i]->pa1 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));
		flame_co[i]->pa2 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));
		flame_co[i]->pa3 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));
		flame_co[i]->pa4 = -2.0 + 1.0 * rand() / RAND_MAX * ( 2.0 - (-2.0));

		flame_co[i]->red = 64 + rand() % (255 - 64);
		flame_co[i]->green = 64 + rand() % (255 - 64);
		flame_co[i]->blue = 64 + rand() % (255 - 64);
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

			x = flame_co[rand_f]->a * p_x + flame_co[rand_f]->b * p_y + flame_co[rand_f]->c;
			y = flame_co[rand_f]->d * p_x + flame_co[rand_f]->e * p_y + flame_co[rand_f]->f;

			/* Spiral */
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
						f_pixel[scr_y][scr_x].r = flame_co[rand_f]->red;
						f_pixel[scr_y][scr_x].g = flame_co[rand_f]->green;
						f_pixel[scr_y][scr_x].b = flame_co[rand_f]->blue;
					}
					else
					{
						f_pixel[scr_y][scr_x].r = + f_pixel[scr_y][scr_x].r + flame_co[rand_f]->red / 2;
						f_pixel[scr_y][scr_x].g = + f_pixel[scr_y][scr_x].g + flame_co[rand_f]->green / 2;
						f_pixel[scr_y][scr_x].b = + f_pixel[scr_y][scr_x].b + flame_co[rand_f]->blue / 2;
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
	while(row < HEIGHT)
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
	while(row < HEIGHT)
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
	while(row < HEIGHT)
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

