/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 19:11:40 by xtang             #+#    #+#             */
/*   Updated: 2020/08/22 19:11:43 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../incl/fractal.h"

int get_color_pattern(int color_index, int iter)
{
	int color_r;
	int color_g;
	int color_b;
	int color_value;

   color_r = 0;
   color_g = 0;
   color_b = 0;
   if (color_index == 1)
	{
		color_r = iter;
		color_g = 0;
		color_b = iter;
	}
   color_value = (color_r << 16) + (color_g << 8) + color_b;
	return (color_value);
}

int assign_col(double newRe, double newIm, int i, t_ctler *ctler)
{
   double iter;
   int     color_value;

   color_value  = 0;
   iter = i - log(log(sqrt(newRe * newRe + newIm * newIm ))) / log(2);
   iter = (767 * iter) / ctler->maxIterate;
   color_value = get_color_pattern(1,i);
   return (color_value);
}