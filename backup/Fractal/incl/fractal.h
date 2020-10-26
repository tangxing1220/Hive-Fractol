/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:37:15 by xtang             #+#    #+#             */
/*   Updated: 2020/08/22 12:37:19 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include "../libft/includes/libft.h" 
#include <math.h>

# define    WIDTH                   1920
# define    HEIGHT                  1080
# define    COL_BACKGROUND			0x000000

typedef struct s_fractal
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *data_addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
}           t_fractal;


typedef struct s_ctler
{
    double  offset_x;
    double  offset_y;
    double  zoom;
    int     choose_color;
    int     maxIterate;
}               t_ctler;

void draw_burningship(t_fractal *fractal);
void draw_julia(t_fractal *fractal, t_ctler *ctler);
void draw_mandelbrot(t_fractal *fractal);
void draw_pixel(t_fractal *fractal, int x, int y, int col);

void ctler_init(t_ctler **ctler);

int assign_col(double newRe, double newIm, int i, t_ctler *ctler);

#endif
