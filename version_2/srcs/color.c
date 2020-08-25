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

int color_rgb_pattern(int r, int g, int b)
{
   return  (r << 16) + (g << 8) + b;
}




int get_color_pattern(int color_index, int i)
{
	if (color_index == 1)
         return (color_rgb_pattern(i, 0, 0));
   else if (color_index == 2)
         return (color_rgb_pattern(0, i, 0));
   else if (color_index == 3)
         return (color_rgb_pattern(0, 0, i));
   else if (color_index == 4)
         return (color_rgb_pattern(i, i, 0));
   else if (color_index == 5)
         return (color_rgb_pattern(i, i, i));
   else if (color_index == 6)
         return (color_rgb_pattern(0, i, i));
   else
         return (color_rgb_pattern(i, 0, i));
   
}

int assign_col(double newRe, double newIm, int i, t_fractal *fractal)
{
   double iter;
   int     color_value;


   iter = (double)i;
   
   if (i == 0)
   {
      color_value  = 0;
   }
   else
   {
      iter = iter - log(log(sqrt(newRe * newRe + newIm * newIm ))) / log(2);
      iter = (767 * iter) / fractal->maxIterate;
      color_value = get_color_pattern(fractal->choose_color,iter);
   }
   return (color_value);

}
