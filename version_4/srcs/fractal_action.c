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
		combi->fra->offset_y -= 0.05;
	}
	else if (key == MLX_ARROW_DOWN)
	{
		combi->fra->offset_y += 0.05;
	}
	else if (key == MLX_ARROW_LEFT)
	{
		combi->fra->offset_x += 0.05;
	}
	else if (key == MLX_ARROW_RIGHT)
	{
		combi->fra->offset_x -= 0.05;
	}
	if (ft_strcmp(combi->fra->name, "julia") == 0)
	{
		draw_image_blackground(combi->fra);
		draw_julia(combi->fra, combi->mouse);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "mandelbrot") == 0)
	{
		draw_image_blackground(combi->fra);
		draw_mandelbrot(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "burningship") == 0)
	{
		draw_image_blackground(combi->fra);
		draw_burningship(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
}

void	fractal_zoom(int button, t_combi *combi)
{
	if (button == MLX_M_SCROLL_UP)
	{
		combi->fra->zoom /= 1.1;
		combi->fra->maxiterate += 4;
		if (combi->fra->maxiterate < 10)
			combi->fra->maxiterate = 10;
	}
	else if (button == MLX_M_SCROLL_DOWN)
	{
		combi->fra->zoom *= 1.1;
		combi->fra->maxiterate -= 4;
	}
	if (ft_strcmp(combi->fra->name, "julia") == 0)
	{
		draw_julia(combi->fra, combi->mouse);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "mandelbrot") == 0)
	{
		draw_mandelbrot(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "burningship") == 0)
	{
		draw_burningship(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
}

void	fractal_reset(t_combi *combi)
{
	combi->fra->choose_color = 1;
	combi->fra->offset_x = 0;
	combi->fra->offset_y = 0;
	combi->fra->maxiterate = 45;
	combi->fra->zoom = 1;
	combi->mouse->mouse_x = 0;
	combi->mouse->mouse_y = 0;
	if (ft_strcmp(combi->fra->name, "julia") == 0)
	{
		draw_julia(combi->fra, combi->mouse);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "mandelbrot") == 0)
	{
		draw_mandelbrot(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "burningship") == 0)
	{
		draw_burningship(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
}

void	iteration_change(int key, t_combi *combi)
{
	if (key == MLX_MAIN_PLUS)
	{
		combi->fra->maxiterate += 3;
	}
	else if (key == MLX_MAIN_MINUS)
	{
		combi->fra->maxiterate -= 3;
	}
	if (combi->fra->maxiterate <= 10)
		combi->fra->maxiterate = 10;
	if (ft_strcmp(combi->fra->name, "julia") == 0)
	{
		draw_julia(combi->fra, combi->mouse);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "mandelbrot") == 0)
	{
		draw_mandelbrot(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
	else if (ft_strcmp(combi->fra->name, "burningship") == 0)
	{
		draw_burningship(combi->fra);
		mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	}
}