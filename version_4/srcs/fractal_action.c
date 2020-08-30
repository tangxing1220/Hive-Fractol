/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 13:39:38 by xtang             #+#    #+#             */
/*   Updated: 2020/08/27 20:02:51 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	fractal_move(int key, t_combi *combi)
{
	if (key == MLX_ARROW_UP)
	{
		combi->fractal->offset_y -= 0.05;
	}
	else if (key == MLX_ARROW_DOWN)
	{
		combi->fractal->offset_y += 0.05;
	}
	else if (key == MLX_ARROW_LEFT)
	{
		combi->fractal->offset_x += 0.05;
	}
	else if (key == MLX_ARROW_RIGHT)
	{
		combi->fractal->offset_x -= 0.05;
	}
	if (ft_strcmp(combi->fractal->name, "julia") == 0)
	{
		draw_image_blackground(combi->fractal);
		draw_julia(combi->fractal, combi->mouse);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "mandelbrot") == 0)
	{
		draw_image_blackground(combi->fractal);
		draw_mandelbrot(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "burningship") == 0)
	{
		draw_image_blackground(combi->fractal);
		draw_burningship(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
}

void	fractal_zoom(int button, t_combi *combi)
{
	if (button == MLX_M_SCROLL_UP)
	{
		combi->fractal->zoom /= 1.1;
		combi->fractal->maxiterate += 4;
		if (combi->fractal->maxiterate < 10)
			combi->fractal->maxiterate = 10;
	}
	else if (button == MLX_M_SCROLL_DOWN)
	{
		combi->fractal->zoom *= 1.1;
		combi->fractal->maxiterate -= 4;
	}
	if (ft_strcmp(combi->fractal->name, "julia") == 0)
	{
		draw_julia(combi->fractal, combi->mouse);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "mandelbrot") == 0)
	{
		draw_mandelbrot(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "burningship") == 0)
	{
		draw_burningship(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
}

void	fractal_reset(t_combi *combi)
{
	combi->fractal->choose_color = 1;
	combi->fractal->offset_x = 0;
	combi->fractal->offset_y = 0;
	combi->fractal->maxiterate = 45;
	combi->fractal->zoom = 1;
	combi->mouse->mouse_x = 0;
	combi->mouse->mouse_y = 0;
	if (ft_strcmp(combi->fractal->name, "julia") == 0)
	{
		draw_julia(combi->fractal, combi->mouse);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "mandelbrot") == 0)
	{
		draw_mandelbrot(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "burningship") == 0)
	{
		draw_burningship(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
}

void	iteration_change(int key, t_combi *combi)
{
	if (key == MLX_MAIN_PLUS)
	{
		combi->fractal->maxiterate += 3;
	}
	else if (key == MLX_MAIN_MINUS)
	{
		combi->fractal->maxiterate -= 3;
	}
	if (combi->fractal->maxiterate <= 10)
		combi->fractal->maxiterate = 10;
	if (ft_strcmp(combi->fractal->name, "julia") == 0)
	{
		draw_julia(combi->fractal, combi->mouse);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "mandelbrot") == 0)
	{
		draw_mandelbrot(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fractal->name, "burningship") == 0)
	{
		draw_burningship(combi->fractal);
		mlx_put_image_to_window(combi->fractal->mlx_ptr,\
				combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
	}
}