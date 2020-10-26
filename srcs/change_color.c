/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:35:21 by xtang             #+#    #+#             */
/*   Updated: 2020/09/08 12:35:35 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	change_color(t_fractal *fra, t_mouse *mouse)
{
	if (ft_strcmp(fra->name, "julia") == 0)
		draw_julia(fra, mouse);
	else if (ft_strcmp(fra->name, "mandelbrot") == 0)
		draw_mandelbrot(fra);
	else if (ft_strcmp(fra->name, "burningship") == 0)
		draw_burningship(fra);
	else if (ft_strcmp(fra->name, "chaosgame") == 0)
		draw_chaosgame(fra);
	else if (ft_strcmp(fra->name, "flame") == 0)
		draw_flame(fra);
	mlx_put_image_to_window(fra->mlx_ptr, fra->win_ptr, fra->img_ptr, 0, 0);
	if (ft_strcmp(fra->name, "flame") != 0 &&
		ft_strcmp(fra->name, "chaosgame") != 0)
		show_str_in_image(fra);
}

void	color_pattern(int key, t_combi *combi)
{
	if (key == MAIN_1)
		combi->fra->choose_color = 1;
	else if (key == MAIN_2)
		combi->fra->choose_color = 2;
	else if (key == MAIN_3)
		combi->fra->choose_color = 3;
	else if (key == MAIN_4)
		combi->fra->choose_color = 4;
	else if (key == MAIN_5)
		combi->fra->choose_color = 5;
	else if (key == MAIN_6)
		combi->fra->choose_color = 6;
	else if (key == MAIN_7)
		combi->fra->choose_color = 7;
	change_color(combi->fra, combi->mouse);
}
