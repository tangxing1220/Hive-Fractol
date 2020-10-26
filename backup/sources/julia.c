/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:34:02 by xtang             #+#    #+#             */
/*   Updated: 2020/03/04 23:34:06 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "color.h"
#include <stdlib.h>

double map(double value, double in_min, double in_max, double out_min, double out_max)
{
    return (value - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void draw_julia(t_frac *frac)
{
    double  newRe;
    double  newIm;
    double  oldRe;
    double  oldIm;
    double  curRe;
    double  curIm;

    int i;
    int width;
    int height;

    height = 0;
    while(height < HEIGHT)
    {
        width = 0;
        while (width < WIDTH)
        {
            newRe = map(width, 0, WIDTH, frac->zoom->min, frac->zoom->max);
            newIm = map(height, 0, HEIGHT, frac->zoom->min, frac->zoom->max);
 //           newRe = 3 * (width - WIDTH / 2) / (frac->control->zoom * WIDTH) + frac->control->offset_x;
 //           newIm = 2 * (height - HEIGHT / 2) / (frac->control->zoom * HEIGHT) + frac->control->offset_y;
            oldRe = newRe;
            oldIm = newIm;
            
            i = 0;
            while (i < frac->control->maxIterate)
            {
                
                curRe = newRe * newRe - newIm * newIm;
                curIm = 2 * newRe * newIm;

                newRe = curRe + oldRe;
                newIm = curIm + oldIm;

                if ((newRe + newIm) > 2)
                    break;
                i++;
            }
            put_pixel(frac, width, height, get_color(frac, newRe, newIm, i)); 
            width++; 
        }
        height++;
    }
}