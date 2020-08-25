/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 16:52:44 by xtang             #+#    #+#             */
/*   Updated: 2020/08/22 16:52:48 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incl/fractal.h"

void draw_burningship(t_fractal *fractal)
{
    double cRe;
    double cIm;
    double newRe;
    double newIm;
    double oldRe;
    double oldIm;

    int maxIterate;
    int i;
    int width;
    int height;
    int col;

    maxIterate = 50;

    height = 0;
    while(height < HEIGHT)
    {
        width = 0;
        while(width < WIDTH)
        {
            newRe = 3 * (width - WIDTH / 2) / (fractal->zoom * WIDTH) + fractal->offset_x;
            newIm = 2 * (height - HEIGHT / 2) / (fractal->zoom * HEIGHT) + fractal->offset_y;
            cRe = newRe;
            cIm = newIm;
            i = 0;
            while(i < maxIterate)
            {
                oldRe = newRe;
                oldIm = newIm;
                newRe = oldRe * oldRe - oldIm * oldIm + cRe;
                newIm = 2 * fabs(oldRe * oldIm) + cIm;
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

