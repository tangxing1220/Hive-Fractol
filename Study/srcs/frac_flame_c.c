/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:47:10 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 15:47:13 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	input_a(t_plane *p, double x, double y)
{
	p->x = x;
	p->y = y;
}

void	input_b(t_plane *p, double x, double y)
{
	p->x = 2.0 * x;
	p->y = y;
}

void	input_c(t_plane *p, double x, double y)
{
	p->x = x;
	p->y = y * 0.5;
}

void	input_d(t_plane *p, double x, double y)
{
	p->x = 2.0 * x;
	p->y = y * 0.5;
}
