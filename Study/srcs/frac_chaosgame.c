/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_chaosgame.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 14:39:15 by xtang             #+#    #+#             */
/*   Updated: 2020/10/21 16:37:08 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	draw_chaosgame(t_fractal *fra)
{
	int		c_x;
	int		c_y;
	int		n_x;
	int		n_y;
	int		*s_x;
	int		*s_y;
	int		i;
	int		j;
	time_t	t;
	int		r;
	float	present;
	float	angle;
	int		len;
	int		h;
	int		w;

	i = 0;
	h = 0;
	while (h < HEIGHT)
	{
		w = 0;
		while (w < WIDTH)
		{
			i = w * fra->bits_per_pixel / 8 + h * fra->size_line;
			fra->data_addr[i] = 0;
			fra->data_addr[++i] = 0;
			fra->data_addr[++i] = 0;
			fra->data_addr[++i] = 0;
			w++;
		}
		h++;
	}
	s_x = (int *)malloc(sizeof(int) * fra->chaosgame_seed);
	s_y = (int *)malloc(sizeof(int) * fra->chaosgame_seed);
	present = 0.58;
	srand((unsigned)time(&t));
	c_x = WIDTH / 2;
	c_y = HEIGHT / 2;
	len = (int)(HEIGHT / 2 * 0.60);
	j = 0;
	while (j < fra->chaosgame_seed)
	{
		angle = j * 2 * M_PI / fra->chaosgame_seed;
		s_x[j] = WIDTH / 2 + len * cos(angle);
		s_y[j] = HEIGHT / 2 + len * sin(angle);
		draw_pixel(fra, s_x[j], s_y[j], 0xFF4500);
		j++;
	}
	i = 0;
	while (i < 100000)
	{
		r = rand() % fra->chaosgame_seed;
		n_x = s_x[r];
		n_y = s_y[r];
		c_x = c_x + (n_x - c_x) * present;
		c_y = c_y + (n_y - c_y) * present;
		draw_pixel(fra, c_x, c_y, 0xFFFF00);
		i++;
	}
	free(s_x);
	free(s_y);
}

void	chaosgame_pattern(int key, t_combi *combi)
{
	if (key == MAIN_PLUS)
		combi->fra->chaosgame_seed++;
	else if (key == MAIN_MINUS)
		combi->fra->chaosgame_seed--;
	if (combi->fra->chaosgame_seed < 1)
		combi->fra->chaosgame_seed = 1;
	if (combi->fra->chaosgame_seed > 100)
		combi->fra->chaosgame_seed = 100;
	fractal_redraw(combi);
}
