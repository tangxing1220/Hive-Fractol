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

void	fractal_redraw(t_combi *combi)
{
	if (ft_strcmp(combi->fra->name, "julia") == 0)
	{
		draw_image_blackground(combi->fra);
		draw_julia(combi->fra, combi->mouse);
	}
	else if (ft_strcmp(combi->fra->name, "mandelbrot") == 0)
	{
		draw_image_blackground(combi->fra);
		draw_mandelbrot(combi->fra);
	}
	else if (ft_strcmp(combi->fra->name, "burningship") == 0)
	{
		draw_image_blackground(combi->fra);
		draw_burningship(combi->fra);
	}
	mlx_put_image_to_window(combi->fra->mlx_ptr,\
				combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
	mlx_string_put(combi->fra->mlx_ptr, combi->fra->win_ptr, WIDTH - 165,\
		HEIGHT - 30, 0xFFFFFF, "Iteration: ");
	mlx_string_put(combi->fra->mlx_ptr, combi->fra->win_ptr, WIDTH - 60,\
		HEIGHT - 30, 0xFFFFFF, ft_itoa(combi->fra->maxiterate));
}

void	fractal_move(int key, t_combi *combi)
{
	if (key == ARROW_UP)
	{
		combi->fra->offset_y -= 0.05;
	}
	else if (key == ARROW_DOWN)
	{
		combi->fra->offset_y += 0.05;
	}
	else if (key == ARROW_LEFT)
	{
		combi->fra->offset_x += 0.05;
	}
	else if (key == ARROW_RIGHT)
	{
		combi->fra->offset_x -= 0.05;
	}
	fractal_redraw(combi);
}

void	fractal_zoom(int button, t_combi *combi)
{
	if (button == M_SCROLL_UP)
	{
		combi->fra->zoom /= 1.1;
		combi->fra->maxiterate += 4;
		if (combi->fra->maxiterate < 10)
			combi->fra->maxiterate = 10;
	}
	else if (button == M_SCROLL_DOWN)
	{
		combi->fra->zoom *= 1.1;
		combi->fra->maxiterate -= 4;
	}
	fractal_redraw(combi);
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
	fractal_redraw(combi);
}

void	iteration_change(int key, t_combi *combi)
{
	if (key == MAIN_PLUS)
	{
		combi->fra->maxiterate += 3;
	}
	else if (key == MAIN_MINUS)
	{
		combi->fra->maxiterate -= 3;
	}
	if (combi->fra->maxiterate <= 10)
		combi->fra->maxiterate = 10;
	fractal_redraw(combi);
}
