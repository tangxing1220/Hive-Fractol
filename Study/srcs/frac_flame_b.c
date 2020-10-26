/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame_e.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:45:48 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 15:45:52 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	variation_select_a(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r2;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	if (th->fra->flame_p == 0)
	{
		p->x = x;
		p->y = y;
	}
	else if (th->fra->flame_p == 1)
	{
		p->x = sin(x);
		p->y = sin(y);
	}
	else if (th->fra->flame_p == 2)
	{
		r2 = x * x + y * y;
		p->x = 1.0 / r2 * x;
		p->y = 1.0 / r2 * y;
	}
}

void	variation_select_b(t_multi_th *th, t_plane *p,\
											t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 3)
	{
		p->x = x * sin(x * x + y * y) - y * cos(x * x + y * y);
		p->y = x * cos(x * x + y * y) - y * sin(x * x + y * y);
	}
	else if (th->fra->flame_p == 4)
	{
		p->x = atan2(y, x) / M_PI;
		p->y = r - 1;
	}
	else if (th->fra->flame_p == 5)
	{
		p->x = r * sin(atan2(y, x) + r);
		p->y = r * cos(atan2(y, x) - r);
	}
}

void	variation_select_c(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 6)
	{
		p->x = r * sin(atan2(y, x) * r);
		p->y = -1 * r * cos(atan2(y, x) * r);
	}
	else if (th->fra->flame_p == 7)
	{
		p->x = atan2(y, x) / M_PI * sin(M_PI * r);
		p->y = atan2(y, x) / M_PI * cos(M_PI * r);
	}
	else if (th->fra->flame_p == 8)
	{
		p->x = 1 / r * (cos(atan2(y, x)) + sin(r));
		p->y = 1 / y * (sin(atan2(y, x)) - cos(r));
	}
}

void	variation_select_d(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 9)
	{
		p->x = sin(theta) / r;
		p->y = r * cos(theta);
	}
	else if (th->fra->flame_p == 10)
	{
		p->x = sin(theta) * cos(r);
		p->y = cos(theta) * sin(r);
	}
}

void	variation_select_e(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;
	double	theta;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	theta = atan2(y, x);
	if (th->fra->flame_p == 11)
	{
		p->x = r * (sin(theta + r) * sin(theta + r) * sin(theta + r) +\
				cos(theta - r) * cos(theta - r) * cos(theta - r));
		p->y = r * (sin(theta + r) * sin(theta + r) * sin(theta + r) -\
				cos(theta - r) * cos(theta - r) * cos(theta - r));
	}
	else if (th->fra->flame_p == 12)
	{
		r = sqrt(x * x + y * y);
		theta = atan2(y, x);
		p->x = sqrt(r) * cos(theta / 2);
		p->y = sqrt(r) * sin(theta / 2);
	}
}
