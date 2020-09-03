/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:01:31 by xtang             #+#    #+#             */
/*   Updated: 2020/08/27 19:42:01 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	draw_pixel(t_fractal *fra, int x, int y, int col)
{
	int i;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		i = (x * (fra->bits_per_pixel / 8) + y * fra->size_line);
		fra->data_addr[i] = col;
		fra->data_addr[++i] = col >> 8;
		fra->data_addr[++i] = col >> 16;
	}
}

void	draw_image_blackground(t_fractal *fractal)
{
	int i;
	int *pixel;

	i = 0;
	if ((fractal->bits_per_pixel / 8) == 4)
		pixel = (int *)(fractal->data_addr);
	while (i < HEIGHT * WIDTH)
	{
		pixel[i] = COL_BACKGROUND;
		i++;
	}
}
