/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 19:19:20 by xtang             #+#    #+#             */
/*   Updated: 2020/08/27 19:39:30 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

int		keyboard_key_press(int key, void *param)
{
	t_combi	*combi;

	combi = (t_combi *)param;
	if (key == MLX_MAIN_ESC)
		exit(0);
	if (key == MLX_ARROW_UP || key == MLX_ARROW_DOWN\
			|| key == MLX_ARROW_LEFT || key == MLX_ARROW_RIGHT)
		fractal_move(key, combi);
	if (key == MLX_MAIN_R)
		fractal_reset(combi);
	if (key == MLX_MAIN_MINUS || key == MLX_MAIN_PLUS)
	{
		iteration_change(key, combi);
	}
	if (key == MLX_MAIN_M)
	{
		if (combi->mouse->mouse_disable == 1)
			combi->mouse->mouse_disable = 0;
		else
			combi->mouse->mouse_disable = 1;
	}
	if (key == MLX_MAIN_1)
		combi->fractal->choose_color = 1;
	else if (key == MLX_MAIN_2)
		combi->fractal->choose_color = 2;
	else if (key == MLX_MAIN_3)
		combi->fractal->choose_color = 3;
	else if (key == MLX_MAIN_4)
		combi->fractal->choose_color = 4;
	else if (key == MLX_MAIN_5)
		combi->fractal->choose_color = 5;
	else if (key == MLX_MAIN_6)
		combi->fractal->choose_color = 6;
	else if (key == MLX_MAIN_7)
		combi->fractal->choose_color = 7;
	change_color(combi->fractal, combi->mouse);
	return (0);
}

int		mouse_movement(int x, int y, void *param)
{
	t_combi *combi;

	combi = (t_combi *)param;
	if (combi->mouse->mouse_disable == 0)
	{
		if (ft_strcmp(combi->fractal->name, "julia") == 0)
		{
			if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
				return (0);
			combi->mouse->mouse_x = -0.002205 * (double)x;
			combi->mouse->mouse_y = 0.00081 * (double)y;
			draw_julia(combi->fractal, combi->mouse);
			mlx_put_image_to_window(combi->fractal->mlx_ptr,\
						combi->fractal->win_ptr, combi->fractal->img_ptr, 0, 0);
		}
	}
	return (0);
}

int		mouse_buttons_press(int button, int x, int y, void *param)
{
	t_combi	*combi;

	(void)x;
	(void)y;
	combi = (t_combi *)param;
	if (button == MLX_M_SCROLL_DOWN || button == MLX_M_SCROLL_UP)
		fractal_zoom(button, combi);
	return (0);
}

void	combi_init(t_combi **combi, t_fractal *fractal, t_mouse *mouse)
{
	*combi = (t_combi *)malloc(sizeof(t_combi));
	(*combi)->fractal = fractal;
	(*combi)->mouse = mouse;
}

void	fractal_controls(t_combi *combi)
{
	mlx_hook(combi->fractal->win_ptr, 4, 0, mouse_buttons_press, combi);
	mlx_hook(combi->fractal->win_ptr, 6, 0, mouse_movement, combi);
	mlx_hook(combi->fractal->win_ptr, 2, 0, keyboard_key_press, combi);
}
