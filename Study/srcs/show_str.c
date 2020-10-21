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

void	show_str_in_image(t_fractal *fra)
{
	int		y;
	void	*win;
	void	*mlx;
	char	*tmp_str;
	char	*var_name;
	char	*tmp_num;

	y = 0;
	win = fra->win_ptr;
	mlx = fra->mlx_ptr;
	if (ft_strcmp(fra->name, "flame") == 0)
	{
		tmp_str = (char *)malloc(sizeof(char) * 40);
		tmp_num = ft_itoa(fra->flame_p);
		if (fra->flame_p == 0)
			var_name = ft_strcpy(tmp_str, "Variation_0 Linear");
		else if (fra->flame_p == 1)
			var_name = ft_strcpy(tmp_str, "Variation_1 Sinusoidal");
		else if (fra->flame_p == 2)
			var_name = ft_strcpy(tmp_str, "Variation_2 Spherical");
		else if (fra->flame_p == 3)
			var_name = ft_strcpy(tmp_str, "Variation_3 Swirl");
		else if (fra->flame_p == 4)
			var_name = ft_strcpy(tmp_str, "Variation_5 Polar");
		else if (fra->flame_p == 5)
			var_name = ft_strcpy(tmp_str, "Variation_6 Handkerchief");
		else if (fra->flame_p == 6)
			var_name = ft_strcpy(tmp_str, "Variation_7 Heart");
		else if (fra->flame_p == 7)
			var_name = ft_strcpy(tmp_str, "Variation_8 Disc");
		else if (fra->flame_p == 8)
			var_name = ft_strcpy(tmp_str, "Variation_9 Spiral");
		else if (fra->flame_p == 9)
			var_name = ft_strcpy(tmp_str, "Variation_10 Hyperbolic");
		else if (fra->flame_p == 10)
			var_name = ft_strcpy(tmp_str, "Variation_11 Diamond");
		else if (fra->flame_p == 11)
			var_name = ft_strcpy(tmp_str, "Variation_12 Ex");
		else if (fra->flame_p == 12)
			var_name = ft_strcpy(tmp_str, "Variation_13 Julia");
		else if (fra->flame_p == 13)
			var_name = ft_strcpy(tmp_str, "Variation_14 Bent");
		else if (fra->flame_p == 14)
			var_name = ft_strcpy(tmp_str, "Variation_15 Waves");
		else if (fra->flame_p == 15)
			var_name = ft_strcpy(tmp_str, "Variation_16 Fisheye");
		else if (fra->flame_p == 16)
			var_name = ft_strcpy(tmp_str, "Variation_17 Popcorn");
		else if (fra->flame_p == 17)
			var_name = ft_strcpy(tmp_str, "Variation_18 Exponential");
		else if (fra->flame_p == 18)
			var_name = ft_strcpy(tmp_str, "Variation_19 Power");
		else if (fra->flame_p == 19)
			var_name = ft_strcpy(tmp_str, "Variation_20 Cosine");
		else if (fra->flame_p == 20)
			var_name = ft_strcpy(tmp_str, "Variation_27 Eyefish");
		else if (fra->flame_p == 21)
			var_name = ft_strcpy(tmp_str, "Variation_28 Bubble");
		else if (fra->flame_p == 22)
			var_name = ft_strcpy(tmp_str, "Variation_29 Cylinder");
		else if (fra->flame_p == 23)
			var_name = ft_strcpy(tmp_str, "Variation_42 Tangent");
		else if (fra->flame_p == 24)
			var_name = ft_strcpy(tmp_str, "Variation_48 Cross");
		else
			var_name = ft_strcpy(tmp_str, "");
		mlx_string_put(mlx, win, 15, y = 20, TXT_COL, "No: ");
		mlx_string_put(mlx, win, 50, y = 20, TXT_COL, tmp_num);
		mlx_string_put(mlx, win, 15, y = 40, TXT_COL, var_name);
		mlx_string_put(mlx, win, WIDTH - 360, HEIGHT - 30, TXT_COL, "('Space':Change'+':Next'-':Last)");
		free(tmp_str);
		free(tmp_num);
	}
	else if (ft_strcmp(fra->name, "chaosgame") == 0)
	{
		tmp_num = ft_itoa(fra->chaosgame_seed);
		mlx_string_put(mlx, win, 15, y = 20, TXT_COL, "Seed: ");
		mlx_string_put(mlx, win, 70, y = 20, TXT_COL, tmp_num);
		mlx_string_put(mlx, win, 15, y = 40, TXT_COL, "('+': more '-':less)");
		free(tmp_num);
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
