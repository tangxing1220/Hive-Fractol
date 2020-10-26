/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:00:23 by xtang             #+#    #+#             */
/*   Updated: 2020/08/22 12:00:30 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void print_usage(void)
{
    ft_putstr_fd("usage: ", STDERR_FILENO);
    ft_putstr_fd("./fractol [fractal type name]\n", STDERR_FILENO);
    ft_putstr_fd("fractal type:\tjulia\tmandelbrot\tburninghsip\n", STDERR_FILENO);
}

void draw_image_blackground(t_fractal *fractal)
{
    int i;
    int *pixel;

    i = 0;
    if((fractal->bits_per_pixel / 8) == 4)
        pixel = (int *)(fractal->data_addr);
    while (i < HEIGHT * WIDTH)
    {
        pixel[i] = COL_BACKGROUND;
        i++;
    }
}

int main(int argc, char **argv)
{
    t_fractal   *fractal;

    if (argc == 2 && (ft_strcmp(argv[1], "burningship") == 0 || ft_strcmp(argv[1],"julia") == 0 || ft_strcmp(argv[1], "mandelbrot") == 0))
    {
        fractal = (t_fractal *)malloc(sizeof(t_fractal));
        fractal->mlx_ptr = mlx_init(); 
        fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT, "Fractal xtang");
        fractal->img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
        fractal->data_addr = mlx_get_data_addr(fractal->img_ptr, \
				&(fractal->bits_per_pixel), &(fractal->size_line), &(fractal->endian));
        fractal->offset_x = 0;
        fractal->offset_y = 0;
        fractal->zoom = 1;
        fractal->choose_color = 1;
        fractal->maxIterate = 50;

        draw_image_blackground(fractal);
        if (ft_strcmp(argv[1], "burningship") == 0)
            draw_burningship(fractal);
        else if (ft_strcmp(argv[1], "julia") == 0)
            draw_julia(fractal);
        else 
            draw_mandelbrot(fractal);
        mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, fractal->img_ptr, 0, 0);
        fractal_controls(fractal);
        mlx_loop(fractal->mlx_ptr);
    }
    else
        print_usage();        
    return (1);
}


