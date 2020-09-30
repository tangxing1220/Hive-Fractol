/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:10:26 by xtang             #+#    #+#             */
/*   Updated: 2020/09/08 12:28:58 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	show_str_in_image(t_fractal *fra)
{
	int		y;
	void	*win;
	void	*mlx;
	char	*tmp_str;

	y = 0;
	win = fra->win_ptr;
	mlx = fra->mlx_ptr;
	tmp_str = ft_itoa(fra->maxiterate);
	mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "Zoom    : Mouse Scroll");
	mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "Move    : Arrows");
	mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "Reset   : R");
	mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "Exit    : ESC");
	mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "Colors  : 1 - 7");
	mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "Iterate : -/+");
	if (ft_strcmp(fra->name, "julia") == 0)
	{
		mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "For Julia :");
		mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "Toggle M Key to");
		mlx_string_put(mlx, win, 15, y += 20, TXT_COL, "mouse movement");
	}
	mlx_string_put(mlx, win, WIDTH - 165, HEIGHT - 30, TXT_COL, "Iteration: ");
	mlx_string_put(mlx, win, WIDTH - 60, HEIGHT - 30, TXT_COL, tmp_str);
	free(tmp_str);
}
