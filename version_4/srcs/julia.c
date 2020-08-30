/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:54:24 by xtang             #+#    #+#             */
/*   Updated: 2020/08/27 20:11:34 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	draw_julia(t_fractal *fractal, t_mouse *mouse)
{
	double	cre;
	double	cim;
	double	newre;
	double	newim;
	double	oldre;
	double	oldim;
	int		i;
	int		width;
	int		height;
	int		col;

	cre = -0.7 + mouse->mouse_x;
	cim = 0.27015 + mouse->mouse_y;
	height = 0;
	while (height < HEIGHT)
	{
		width = 0;
		while (width < WIDTH)
		{
			newre = (3 * (width - WIDTH / 2) * fractal->zoom) /\
						(fractal->zoom * WIDTH) + fractal->offset_x;
			newim = (2 * (height - HEIGHT / 2) * fractal->zoom) /\
						(fractal->zoom * HEIGHT) + fractal->offset_y;
			i = 0;
			while (i < fractal->maxiterate)
			{
				oldre = newre;
				oldim = newim;
				newre = oldre * oldre - oldim * oldim + cre;
				newim = 2 * oldre * oldim + cim;
				if ((newre * newre + newim * newim) > 4)
					break ;
				i++;
			}
			col = assign_col(newre, newim, i, fractal);
			draw_pixel(fractal, width, height, col);
			width++;
		}
		height++;
	}
}
