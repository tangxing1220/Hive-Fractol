/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:54:24 by xtang             #+#    #+#             */
/*   Updated: 2020/08/22 16:54:26 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void draw_julia(t_fractal *fractal, t_mouse *mouse)
{
    double cRe;
    double cIm;
    double newRe;
    double newIm;
    double oldRe;
    double oldIm;

    int i;
    int width;
    int height;
    int col;

    cRe = -0.7 + mouse->mouse_x;
    cIm = 0.27015 + mouse-> mouse_y;

    height = 0;
    while(height < HEIGHT)
    {
        
        width = 0;
        while(width < WIDTH)
        {
            newRe = (3 * (width - WIDTH / 2) * fractal->zoom) / (fractal->zoom * WIDTH) + fractal->offset_x;
            newIm = (2 * (height - HEIGHT / 2) *fractal->zoom) / (fractal->zoom * HEIGHT) + fractal->offset_y;
            i = 0;
            while(i < fractal->maxIterate)
            {
                oldRe = newRe;
                oldIm = newIm;
                newRe = oldRe * oldRe - oldIm * oldIm + cRe;
                newIm = 2 * oldRe * oldIm + cIm;
                if ((newRe * newRe + newIm * newIm) > 4)
                    break;
                i++; 
            }
            col = assign_col(newRe, newIm, i, fractal);
            draw_pixel(fractal, width, height, col);
            width++;
        }
        height++;
    }
}