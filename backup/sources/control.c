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
	if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == MOUSE_SCROLL_UP) 
		frac->control->zoom *= 1.1;
	else if (key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS
		|| key == MOUSE_SCROLL_DOWN)
		frac->control->zoom /= 1.1;
	else if ( key == MAIN_PAD_A)
	{
		frac->zoom->max -= 0.1 * frac->zoom->factor;
    	frac->zoom->min += 0.15 * frac->zoom->factor;
    	frac->zoom->factor *= 0.9349;
    	frac->control->maxIterate += 5;
    	frac->zoom->count++;

     	if (frac->zoom->count > 30)
    	{
        	frac->control->maxIterate *= 1.02;
    	}
	}
	draw(frac, "julia");
}

void	move(int key, t_frac *frac)
{
	if (key == ARROW_UP)
	{
		frac->control->offset_y += 1 / (frac->control->zoom * 100);
	}
	else if (key == ARROW_DOWN)
	{
		frac->control->offset_y -= 1 / (frac->control->zoom * 100);
	}
	else if (key == ARROW_LEFT)
	{
		frac->control->offset_x += 1 / (frac->control->zoom * 100);
	}
	else if (key == ARROW_RIGHT)
	{
		frac->control->offset_x -= 1 / (frac->control->zoom * 100);
	}

	draw(frac, "julia");
}

void	change_color(int key, t_frac *frac)
{
	if (key == NUM_PAD_1 || key == MAIN_PAD_1)
		frac->control->select_color = 1;
	else if (key == NUM_PAD_2 || key == MAIN_PAD_2)
		frac->control->select_color = 2;
	else if (key == NUM_PAD_3 || key == MAIN_PAD_3)
		frac->control->select_color = 3;
	else if (key == NUM_PAD_4 || key == MAIN_PAD_4)
		frac->control->select_color = 4;
	else if (key == NUM_PAD_5 || key == MAIN_PAD_5)
		frac->control->select_color = 5;
	else if (key == NUM_PAD_6 || key == MAIN_PAD_6)
		frac->control->select_color = 6;
	else if (key == NUM_PAD_7 || key == MAIN_PAD_7)
		frac->control->select_color = 7;
	draw(frac, "julia");
}


int			key_press(int key, void *param)
{
	t_frac	*frac;

	frac = (t_frac *)param;
	if (key == MAIN_PAD_ESC)
	{
		exit(0);
	}
	else if (key == NUM_PAD_1 || key == MAIN_PAD_1
		|| key == NUM_PAD_2 || key == MAIN_PAD_2
		|| key == NUM_PAD_3 || key == MAIN_PAD_3
		|| key == NUM_PAD_4 || key == MAIN_PAD_5
		|| key == NUM_PAD_5 || key == MAIN_PAD_4
		|| key == NUM_PAD_6 || key == MAIN_PAD_6
		|| key == NUM_PAD_7 || key == MAIN_PAD_7)
	{
		change_color(key, frac);
	}
	else if (key == NUM_PAD_PLUS || key == MAIN_PAD_PLUS
		|| key == NUM_PAD_MINUS || key == MAIN_PAD_MINUS
		|| key == MAIN_PAD_A)
	{
		zoom(key, frac);
	}
	else if (key == ARROW_UP || key == ARROW_DOWN
		|| key == ARROW_LEFT || key == ARROW_RIGHT)
	{
		move(key, frac);
	}
	return (0);
}

/*
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
	//	draw(frac, frac_name);
        draw_julia(frac);
	}
	return (0);
}
*/
void	setup_controls(t_frac *frac)
{
	mlx_hook(frac->win, 2, 0, key_press, frac);
//	mlx_hook(frac->win, 17, 0, ft_close, frac);
//	mlx_hook(frac->win, 4, 0, mouse_press, frac);
//	mlx_hook(frac->win, 5, 0, mouse_release, frac);
//	mlx_hook(frac->win, 6, 0, mouse_move, frac);
}
