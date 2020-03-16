/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiantian <xtang@student.hive.fi>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 23:31:45 by tiantian          #+#    #+#             */
/*   Updated: 2020/03/14 23:31:49 by tiantian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void draw_mandelbrot(t_frac *frac)
{
    double pRe;
    double pIm;

    double newRe;
    double newIm;
    double oldRe;
    double oldIm;
    double zoom;
    double offset_x;
    double offset_y;
    int maxIterate;

    zoom = 1;
    offset_x = -0.5;
    offset_y = 0;
    maxIterate = 300;

    int i;
    int width;
    int height;

    height = 0;
    while(height < HEIGHT)
    {
        width = 0;
        while (width < WIDTH)
        {
            pRe = 1.5 * (width - WIDTH/2) / (0.5 * zoom * WIDTH) + offset_x;
            pIm = (height -HEIGHT/2) / (0.5 * zoom * HEIGHT) + offset_y;

            newRe = 0;
            newIm = 0;
            oldRe = 0;
            oldIm = 0;
        
            i = 0;
            while (i < maxIterate)
            {
                oldRe = newRe;
                oldIm = newIm;

                newRe = oldRe * oldRe - oldIm *oldIm + pRe;
                newIm = 2 * oldRe * oldIm + pIm;

                if ((newRe * newRe + newIm * newIm) > 4)
                    break;
                i++;
            }
            put_pixel(frac, width, height, get_color(frac, newRe, newIm, i)); 
            width++; 
        }
        height++;
    }
}
