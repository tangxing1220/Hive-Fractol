/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_chaosgame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:39:15 by xtang             #+#    #+#             */
/*   Updated: 2020/10/07 16:58:35 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void		draw_chaosgame(t_fractal *fra)
{
	int		c_x;
	int		c_y;
	int		n_x;
	int		n_y;
	int		s_x[SEED];
	int		s_y[SEED];
	int		i;
	int		j;
	time_t	t;
	int		r;
	float	present;
	float	angle;
	int		len;

	present = 0.58;
	srand((unsigned)time(&t));
	c_x = WIDTH / 2;
	c_y = HEIGHT / 2;
	len = (int)(HEIGHT / 2 * 0.60);
	j = 0;
	while (j < SEED)
	{
		angle = j * 2 * M_PI / SEED;
		s_x[j] = WIDTH / 2 + len * cos(angle);
		s_y[j] = HEIGHT / 2 + len * sin(angle);
		draw_pixel(fra, s_x[j], s_y[j], 0xFF4500);
		j++;
	}
	i = 0;
	while (i < 100000)
	{
		r = rand() % SEED;
		n_x = s_x[r];
		n_y = s_y[r];
		c_x = c_x + (n_x - c_x) * present;
		c_y = c_y + (n_y - c_y) * present;
		draw_pixel(fra, c_x, c_y, 0xFFFF00);
		i++;
	}
}
