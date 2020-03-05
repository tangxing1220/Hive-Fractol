/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 00:33:17 by xtang             #+#    #+#             */
/*   Updated: 2020/03/05 00:33:20 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    put_pixel(t_frac *frac, int x, int y, int color)
{
    int		i;

	if (x >= MENU_WIDTH && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * frac->bits_per_pixel / 8) + (y * frac->size_line);
		frac->data_addr[i] = color;
		frac->data_addr[++i] = color >> 8;
		frac->data_addr[++i] = color >> 16;
	}

}



int     get_color(int i)
{


}

