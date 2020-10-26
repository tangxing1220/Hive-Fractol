/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_str_flame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:29:18 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 14:29:22 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

char	*flame_name_a(t_fractal *fra)
{
	char *tmp_str;

	tmp_str = (char *)malloc(sizeof(char) * 40);
	if (fra->flame_p == 0)
		ft_strcpy(tmp_str, "Variation_0 Linear");
	else if (fra->flame_p == 1)
		ft_strcpy(tmp_str, "Variation_1 Sinusoidal");
	else if (fra->flame_p == 2)
		ft_strcpy(tmp_str, "Variation_2 Spherical");
	else if (fra->flame_p == 3)
		ft_strcpy(tmp_str, "Variation_3 Swirl");
	else if (fra->flame_p == 4)
		ft_strcpy(tmp_str, "Variation_5 Polar");
	else if (fra->flame_p == 5)
		ft_strcpy(tmp_str, "Variation_6 Handkerchief");
	else if (fra->flame_p == 6)
		ft_strcpy(tmp_str, "Variation_7 Heart");
	else if (fra->flame_p == 7)
		ft_strcpy(tmp_str, "Variation_8 Disc");
	else
		ft_strcpy(tmp_str, "");
	return (tmp_str);
}

char	*flame_name_b(t_fractal *fra)
{
	char *tmp_str;

	tmp_str = (char *)malloc(sizeof(char) * 40);
	if (fra->flame_p == 8)
		ft_strcpy(tmp_str, "Variation_9 Spiral");
	else if (fra->flame_p == 9)
		ft_strcpy(tmp_str, "Variation_10 Hyperbolic");
	else if (fra->flame_p == 10)
		ft_strcpy(tmp_str, "Variation_11 Diamond");
	else if (fra->flame_p == 11)
		ft_strcpy(tmp_str, "Variation_12 Ex");
	else if (fra->flame_p == 12)
		ft_strcpy(tmp_str, "Variation_13 Julia");
	else if (fra->flame_p == 13)
		ft_strcpy(tmp_str, "Variation_14 Bent");
	else if (fra->flame_p == 14)
		ft_strcpy(tmp_str, "Variation_15 Waves");
	else if (fra->flame_p == 15)
		ft_strcpy(tmp_str, "Variation_16 Fisheye");
	else
		ft_strcpy(tmp_str, "");
	return (tmp_str);
}

char	*flame_name_c(t_fractal *fra)
{
	char *tmp_str;

	tmp_str = (char *)malloc(sizeof(char) * 40);
	if (fra->flame_p == 16)
		ft_strcpy(tmp_str, "Variation_17 Popcorn");
	else if (fra->flame_p == 17)
		ft_strcpy(tmp_str, "Variation_18 Exponential");
	else if (fra->flame_p == 18)
		ft_strcpy(tmp_str, "Variation_19 Power");
	else if (fra->flame_p == 19)
		ft_strcpy(tmp_str, "Variation_20 Cosine");
	else if (fra->flame_p == 20)
		ft_strcpy(tmp_str, "Variation_27 Eyefish");
	else if (fra->flame_p == 21)
		ft_strcpy(tmp_str, "Variation_28 Bubble");
	else if (fra->flame_p == 22)
		ft_strcpy(tmp_str, "Variation_29 Cylinder");
	else if (fra->flame_p == 23)
		ft_strcpy(tmp_str, "Variation_42 Tangent");
	else
		ft_strcpy(tmp_str, "");
	return (tmp_str);
}

char	*flame_name_d(t_fractal *fra)
{
	char *tmp_str;

	tmp_str = (char *)malloc(sizeof(char) * 40);
	if (fra->flame_p == 24)
		ft_strcpy(tmp_str, "Variation_48 Cross");
	else
		ft_strcpy(tmp_str, "");
	return (tmp_str);
}

void	str_flame(t_fractal *fra)
{
	void	*win;
	void	*mlx;
	char	*tmp_num;
	char	*var_name;

	win = fra->win_ptr;
	mlx = fra->mlx_ptr;
	tmp_num = ft_itoa(fra->flame_p);
	if (fra->flame_p >= 0 && fra->flame_p <= 7)
		var_name = flame_name_a(fra);
	else if (fra->flame_p >= 8 && fra->flame_p <= 15)
		var_name = flame_name_b(fra);
	else if (fra->flame_p >= 16 && fra->flame_p <= 23)
		var_name = flame_name_c(fra);
	else
		var_name = flame_name_d(fra);
	mlx_string_put(mlx, win, 15, 20, TXT_COL, "No: ");
	mlx_string_put(mlx, win, 50, 20, TXT_COL, tmp_num);
	mlx_string_put(mlx, win, 15, 40, TXT_COL, var_name);
	mlx_string_put(mlx, win, WIDTH - 360, HEIGHT - 30, TXT_COL,\
								"('Space':Change'+':Next'-':Last)");
	free(tmp_num);
	free(var_name);
}
