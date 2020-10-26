/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:10:26 by xtang             #+#    #+#             */
/*   Updated: 2020/10/21 16:42:16 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	str_chaosgame(t_fractal *fra)
{
	char	*tmp_num;
	void	*win;
	void	*mlx;

	tmp_num = ft_itoa(fra->chaosgame_seed);
	win = fra->win_ptr;
	mlx = fra->mlx_ptr;
	mlx_string_put(mlx, win, 15, 20, TXT_COL, "Seed: ");
	mlx_string_put(mlx, win, 70, 20, TXT_COL, tmp_num);
	mlx_string_put(mlx, win, 15, 40, TXT_COL, "('+': more '-':less)");
	free(tmp_num);
}

void	str_julia_mandelbrot_burningship(t_fractal *fra)
{
	char	*tmp_str;
	void	*win;
	void	*mlx;

	tmp_str = ft_itoa(fra->maxiterate);
	win = fra->win_ptr;
	mlx = fra->mlx_ptr;
	mlx_string_put(mlx, win, 15, 20, TXT_COL, "Zoom    : Mouse Scroll");
	mlx_string_put(mlx, win, 15, 40, TXT_COL, "Move    : Arrows");
	mlx_string_put(mlx, win, 15, 60, TXT_COL, "Reset   : R");
	mlx_string_put(mlx, win, 15, 80, TXT_COL, "Exit    : ESC");
	mlx_string_put(mlx, win, 15, 100, TXT_COL, "Colors  : 1 - 7");
	mlx_string_put(mlx, win, 15, 120, TXT_COL, "Iterate : -/+");
	mlx_string_put(mlx, win, WIDTH - 165, HEIGHT - 30, TXT_COL, "Iteration: ");
	mlx_string_put(mlx, win, WIDTH - 60, HEIGHT - 30, TXT_COL, tmp_str);
	free(tmp_str);
	if (ft_strcmp(fra->name, "julia") == 0)
	{
		mlx_string_put(mlx, win, 15, 140, TXT_COL, "For Julia :");
		mlx_string_put(mlx, win, 15, 160, TXT_COL, "Toggle M Key to");
		mlx_string_put(mlx, win, 15, 180, TXT_COL, "mouse movement");
	}
}

void	show_str_in_image(t_fractal *fra)
{
	if (ft_strcmp(fra->name, "flame") == 0)
		str_flame(fra);
	else if (ft_strcmp(fra->name, "chaosgame") == 0)
		str_chaosgame(fra);
	else if (ft_strcmp(fra->name, "julia") == 0\
				|| ft_strcmp(fra->name, "mandelbrot") == 0\
				|| ft_strcmp(fra->name, "burningship") == 0)
		str_julia_mandelbrot_burningship(fra);
}
