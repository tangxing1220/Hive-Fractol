/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 17:01:31 by xtang             #+#    #+#             */
/*   Updated: 2020/08/22 17:01:35 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void draw_pixel(t_fractal *fractal, int x, int y, int col)
{
    int i;

    if ((x >= 0 && x < WIDTH) && (y>=0 && y < HEIGHT))
    {
        i = (x * (fractal->bits_per_pixel / 8) + y * fractal->size_line);
        fractal->data_addr[i] = col;
        fractal->data_addr[++i] = col >> 8;
        fractal->data_addr[++i] = col >> 16;
    }
}
