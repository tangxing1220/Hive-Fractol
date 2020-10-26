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
