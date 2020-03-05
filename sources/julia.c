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

void draw_julia(t_frac *frac)
{
    double  cRe;
    double  cIm;
    double  newRe;
    double  newIm;
    double  oldRe;
    double  oldIm;

    double zoom;
    double offset_x;
    double offset_y;

    int maxIterate;
    int i;
    int width;
    int height;

    double time;
    double old_time;
    double frame_time;

    
    zoom = 1;
    offset_x = 0;
    offset_y = 0;
    cRe = -0.7;
    cIm = 0.27015;
    
    while(1)
    {
        height = 0;
        while(height < HEIGHT)
        {
            width = 0;
            while (width < WIDTH)
            {
                newRe = 3 * (width - WIDTH / 2) / (zoom * WIDTH) + offset_x;
                newIm = 2 * (height - HEIGHT / 2) / (zoom *HEIGHT) + offset_y;
                i = 0;
                while (i < maxIterate)
                {
                    oldRe = newRe;
                    oldIm = newIm;

                    newRe = oldRe * oldRe - oldIm * oldIm + cRe;
                    newIm = 2 * oldRe * oldIm + cIm;
                    if ((newRe * newRe + newIm * newIm) > 4)
                        break;
                    i++;
                }
                put_pixel(frac, width, height, get_color(i));            
                width++; 
            }
            height++;
        }










    }






}