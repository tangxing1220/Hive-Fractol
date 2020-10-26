/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:40:27 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 15:40:31 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

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
