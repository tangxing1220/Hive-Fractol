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
#include "mlx.h"

# define    WIDTH                   1920
# define    HEIGHT                  1080
# define    MENU_WIDTH              250
# define    MENU_HEIGHT             1080
# define    COL_BACKGROUND			0x000000

# define    MLX_MAIN_ESC            53

# define    MLX_MAIN_1              18
# define    MLX_MAIN_2              19
# define    MLX_MAIN_3              20
# define    MLX_MAIN_4              21
# define    MLX_MAIN_5              23
# define    MLX_MAIN_6              22
# define    MLX_MAIN_7              26              

typedef struct s_fractal
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    char    *data_addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
    double  offset_x;
    double  offset_y;
    double  zoom;
    int     choose_color;
    int     maxIterate;
}           t_fractal;

void draw_burningship(t_fractal *fractal);
void draw_julia(t_fractal *fractal);
void draw_mandelbrot(t_fractal *fractal);
void draw_pixel(t_fractal *fractal, int x, int y, int col);

int assign_col(double newRe, double newIm, int i, t_fractal *fractal);

void fractal_controls(t_fractal *fractal);

#endif
