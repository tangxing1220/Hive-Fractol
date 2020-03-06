/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 14:09:31 by xtang             #+#    #+#             */
/*   Updated: 2020/03/06 14:09:34 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fractol.h"
#include "keys_macro.h"
#include <stdlib.h>

void	zoom(int key, t_frac *frac)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		frac->control->zoom++;
	else if (key == NUM_PAD_MINUS ||
		key == MAIN_PAD_MINUS ||
		key == MOUSE_SCROLL_DOWN)
		frac->control->zoom--;
//  if (fdf->camera->zoom < 1)
//		fdf->camera->zoom = 1;
	draw(frac);
    draw_julia(frac);
}

int			key_press(int key, void *param)
{
	t_frac	*frac;

	frac = (t_frac *)param;
	if (key == MAIN_PAD_ESC)
		exit(0);
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS)
		zoom(key, frac);
/*	else if (key == ARROW_LEFT || key == ARROW_RIGHT
		|| key == ARROW_UP || key == ARROW_DOWN)
		move(key, frac);
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_3 || key == MAIN_PAD_3
		|| key == NUM_PAD_4 || key == MAIN_PAD_4
		|| key == NUM_PAD_6 || key == MAIN_PAD_6
		|| key == NUM_PAD_7 || key == MAIN_PAD_7
		|| key == NUM_PAD_8 || key == MAIN_PAD_8
		|| key == NUM_PAD_9 || key == MAIN_PAD_9)
		rotate(key, frac);
	else if (key == MAIN_PAD_LESS || key == MAIN_PAD_MORE)
		flatten(key, frac);
	else if (key == MAIN_PAD_P || key == MAIN_PAD_I)
		change_projection(key, frac);
*/
	return (0);
}


int			mouse_move(int x, int y, void *param)
{
	t_frac	*frac;

	frac = (t_frac *)param;
	frac->mouse->previous_x = frac->mouse->x;
	frac->mouse->previous_y = frac->mouse->y;
	frac->mouse->x = x;
	frac->mouse->y = y;
	if (frac->mouse->is_pressed)
	{
		frac->control->offset_x += (x - frac->mouse->previous_x) * 0.002;
		frac->control->offset_y += (y - frac->mouse->previous_y) * 0.002;
		draw(frac);
        draw_julia(frac);
	}
	return (0);
}

void	setup_controls(t_frac *frac)
{
	mlx_hook(frac->win, 2, 0, key_press, frac);
//	mlx_hook(frac->win, 17, 0, ft_close, frac);
//	mlx_hook(frac->win, 4, 0, mouse_press, frac);
//	mlx_hook(frac->win, 5, 0, mouse_release, frac);
//	mlx_hook(frac->win, 6, 0, mouse_move, frac);
}
