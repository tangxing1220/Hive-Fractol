/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frac_flame_g.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 15:49:38 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 15:49:41 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	variation_select_f(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	if (th->fra->flame_p == 13)
	{
		if (x >= 0.0 && y >= 0.0)
			input_a(p, x, y);
		else if (x < 0.0 && y >= 0.0)
			input_b(p, x, y);
		else if (x >= 0.0 && y < 0.0)
			input_c(p, x, y);
		else if (x < 0.0 && y < 0.0)
			input_d(p, x, y);
	}
}

void	variation_select_g(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 14)
	{
		p->x = x + f_co[r_f].b * sin(y / (f_co[r_f].c * f_co[r_f].c));
		p->y = y + f_co[r_f].e * sin(x / (f_co[r_f].f * f_co[r_f].f));
	}
	else if (th->fra->flame_p == 15)
	{
		p->x = 2 / (r + 1) * y;
		p->y = 2 / (r + 1) * x;
	}
	else if (th->fra->flame_p == 16)
	{
		p->x = x + f_co[r_f].c * sin(tan(3 * y));
		p->y = y + f_co[r_f].f * sin(tan(3 * x));
	}
}

void	variation_select_h(t_multi_th *th, t_plane *p,\
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
	if (th->fra->flame_p == 17)
	{
		p->x = exp(x - 1) * cos(M_PI * y);
		p->y = exp(x - 1) * sin(M_PI * y);
	}
	else if (th->fra->flame_p == 18)
	{
		p->x = pow(r, sin(theta)) * cos(theta);
		p->y = pow(r, sin(theta)) * sin(theta);
	}
}

void	variation_select_i(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;
	double	r;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	r = sqrt(x * x + y * y);
	if (th->fra->flame_p == 19)
	{
		p->x = cos(M_PI * x) * cosh(y);
		p->y = -1 * sin(M_PI * x) * sinh(y);
	}
	else if (th->fra->flame_p == 20)
	{
		p->x = 2 / (r + 1) * x;
		p->y = 2 / (r + 1) * y;
	}
	else if (th->fra->flame_p == 21)
	{
		p->x = 4 / (x * x + y * y + 4) * x;
		p->y = 4 / (x * x + y * y + 4) * y;
	}
}

void	variation_select_j(t_multi_th *th, t_plane *p,\
													t_flame_co *f_co, int r_f)
{
	double	x;
	double	y;

	x = f_co[r_f].a * (p->x) + f_co[r_f].b * (p->y) + f_co[r_f].c;
	y = f_co[r_f].d * (p->x) + f_co[r_f].e * (p->y) + f_co[r_f].f;
	if (th->fra->flame_p == 22)
	{
		p->x = sin(x);
		p->y = y;
	}
	else if (th->fra->flame_p == 23)
	{
		p->x = sin(x) / cos(y);
		p->y = tan(y);
	}
	else if (th->fra->flame_p == 24)
	{
		p->x = x / (x * x - y * y);
		p->y = y / (x * x - y * y);
	}
}
