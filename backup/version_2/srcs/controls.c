/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:19:20 by xtang             #+#    #+#             */
/*   Updated: 2020/08/25 19:19:23 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int		keyboard_key_press(int key, void *param)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)param;
	if (key == MLX_MAIN_ESC)
		exit(0);
	
	if (key == MLX_MAIN_1)
		fractal->choose_color = 1;
	else if (key == MLX_MAIN_2)
		fractal->choose_color = 2;
	else if (key == MLX_MAIN_3)
		fractal->choose_color = 3;
	else if (key == MLX_MAIN_4)
		fractal->choose_color = 4;
	else if (key == MLX_MAIN_5)
		fractal->choose_color = 5;
	else if (key == MLX_MAIN_6)
		fractal->choose_color = 6;
	else if (key == MLX_MAIN_7)
		fractal->choose_color = 7;
	return (0);
}

void fractal_controls(t_fractal *fractal)
{
//    mlx_hook(fractal->win_ptr, 4, 0, mouse_buttons_press, fractal);
//	mlx_hook(fractal->win_ptr, 5, 0, mouse_buttons_release, fractal);
//	mlx_hook(fractal->win_ptr, 6, 0, mouse_movement, fractal);
	mlx_hook(fractal->win_ptr, 2, 0, keyboard_key_press, fractal);
}
