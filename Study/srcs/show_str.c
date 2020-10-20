/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:10:26 by xtang             #+#    #+#             */
/*   Updated: 2020/10/20 19:39:29 by xtang            ###   ########.fr       */
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
	if (ft_strcmp(fra->name, "flame") == 0)
	{
		if (fra->flame_p == 0)
			tmp_str = "Variation_0 Linear";
		else if (fra->flame_p == 1)
			tmp_str = "Variation_1 Sinusoidal";
		else if (fra->flame_p == 2)
			tmp_str = "Variation_2 Spherical";
		else if (fra->flame_p == 3)
			tmp_str = "Variation_3 Swirl";
		else if (fra->flame_p == 4)
			tmp_str = "Variation_5 Polar";
		else if (fra->flame_p == 5)
			tmp_str = "Variation_6 Handkerchief";
		else if (fra->flame_p == 6)
			tmp_str = "Variation_7 Heart";
		else if (fra->flame_p == 7)
			tmp_str = "Variation_8 Disc";
		else if (fra->flame_p == 8)
			tmp_str = "Variation_9 Spiral";
		else if (fra->flame_p == 9)
			tmp_str = "Variation_10 Hyperbolic";
		else if (fra->flame_p == 10)
			tmp_str = "Variation_11 Diamond";
		else if (fra->flame_p == 11)
			tmp_str = "Variation_12 Ex";
		else if (fra->flame_p == 12)
			tmp_str = "Variation_13 Julia";
		else if (fra->flame_p == 13)
			tmp_str = "Variation_14 Bent";
		else if (fra->flame_p == 14)
			tmp_str = "Variation_15 Waves";
		else if (fra->flame_p == 15)
			tmp_str = "Variation_16 Fisheye";
		else if (fra->flame_p == 16)
			tmp_str = "Variation_17 Popcorn";
		else if (fra->flame_p == 17)
			tmp_str = "Variation_18 Exponential";
		else if (fra->flame_p == 18)
			tmp_str = "Variation_19 Power";
		else if (fra->flame_p == 19)
			tmp_str = "Variation_20 Cosine";
		else if (fra->flame_p == 20)
			tmp_str = "Variation_27 Eyefish";
		else if (fra->flame_p == 21)
			tmp_str = "Variation_28 Bubble";
		else if (fra->flame_p == 22)
			tmp_str = "Variation_29 Cylinder";
		else if (fra->flame_p == 23)
			tmp_str = "Variation_42 Tangent";
		else if (fra->flame_p == 24)
			tmp_str = "Variation_48 Cross";
		else
			tmp_str = "";
		mlx_string_put(mlx, win, 15, y = 20, TXT_COL, "No: ");
		mlx_string_put(mlx, win, 50, y = 20, TXT_COL, ft_itoa(fra->flame_p));
		mlx_string_put(mlx, win, 15, y = 40, TXT_COL, tmp_str);
		mlx_string_put(mlx, win, WIDTH - 360, HEIGHT - 30, TXT_COL, "('Space':Change'+':Next'-':Last)");
	}
	else
	{
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
}
