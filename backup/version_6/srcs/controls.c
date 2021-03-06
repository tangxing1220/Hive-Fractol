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
	if (key == MAIN_ESC)
		exit(0);
	if (key == ARROW_UP || key == ARROW_DOWN\
			|| key == ARROW_LEFT || key == ARROW_RIGHT)
		fractal_move(key, combi);
	if (key == MAIN_R)
		fractal_reset(combi);
	if (key == MAIN_MINUS || key == MAIN_PLUS)
		iteration_change(key, combi);
	if (key == MAIN_M)
	{
		if (combi->mouse->mouse_disable == 1)
			combi->mouse->mouse_disable = 0;
		else
			combi->mouse->mouse_disable = 1;
	}
	if (key == MAIN_1 || key == MAIN_2 || key == MAIN_3 ||
		key == MAIN_4 || key == MAIN_5 || key == MAIN_6 || key == MAIN_7)
		color_pattern(key, combi);
	return (0);
}

int		mouse_movement(int x, int y, void *param)
{
	t_combi *combi;

	combi = (t_combi *)param;
	if (combi->mouse->mouse_disable == 0)
	{
		if (ft_strcmp(combi->fra->name, "julia") == 0)
		{
			if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
				return (0);
			combi->mouse->mouse_x = 0.002345 * ((double)x - WIDTH / 2);
			combi->mouse->mouse_y = 0.002345 * ((double)y - HEIGHT / 2);
			draw_julia(combi->fra, combi->mouse);
			mlx_put_image_to_window(combi->fra->mlx_ptr,\
						combi->fra->win_ptr, combi->fra->img_ptr, 0, 0);
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
	if (button == M_SCROLL_DOWN || button == M_SCROLL_UP)
		fractal_zoom(button, combi);
	return (0);
}

void	combi_init(t_combi **combi, t_fractal *fra, t_mouse *mouse)
{
	*combi = (t_combi *)malloc(sizeof(t_combi));
	(*combi)->fra = fra;
	(*combi)->mouse = mouse;
	mlx_string_put(fra->mlx_ptr, fra->win_ptr, WIDTH - 165, HEIGHT - 30,
			0xFFFFFF, "Iteration: ");
	mlx_string_put(fra->mlx_ptr, fra->win_ptr, WIDTH - 60, HEIGHT - 30,
			0xFFFFFF, ft_itoa(fra->maxiterate));
}

void	fractal_controls(t_combi *combi)
{
	mlx_hook(combi->fra->win_ptr, 4, 0, mouse_buttons_press, combi);
	mlx_hook(combi->fra->win_ptr, 6, 0, mouse_movement, combi);
	mlx_hook(combi->fra->win_ptr, 2, 0, keyboard_key_press, combi);
}
