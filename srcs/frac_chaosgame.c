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

void	draw_seed(t_fractal *fra, int *seed_x, int *seed_y)
{
	int		i;
	int		num;
	float	angle;
	int		len;

	num = fra->chaosgame_seed;
	len = (int)(HEIGHT / 2 * 0.60);
	i = 0;
	while (i < num)
	{
		angle = i * 2 * M_PI / num;
		seed_x[i] = WIDTH / 2 + len * cos(angle);
		seed_y[i] = HEIGHT / 2 + len * sin(angle);
		draw_pixel(fra, seed_x[i], seed_y[i], 0xFF4500);
		i++;
	}
}

void	draw_samples(t_fractal *fra, int *seed_x, int *seed_y)
{
	int		i;
	time_t	t;
	int		random;
	int		curr_x;
	int		curr_y;

	srand((unsigned)time(&t));
	i = 0;
	while (i < SAMPLES)
	{
		random = rand() % fra->chaosgame_seed;
		curr_x = curr_x + (seed_x[random] - curr_x) * 0.58;
		curr_y = curr_y + (seed_y[random] - curr_y) * 0.58;
		draw_pixel(fra, curr_x, curr_y, 0xFFFF00);
		i++;
	}
}

void	draw_chaosgame(t_fractal *fra)
{
	int		s_num;
	int		seed_x[fra->chaosgame_seed];
	int		seed_y[fra->chaosgame_seed];

	s_num = fra->chaosgame_seed;
	clean_screen(fra);
	draw_seed(fra, seed_x, seed_y);
	draw_samples(fra, seed_x, seed_y);
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
