/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 14:36:31 by xtang             #+#    #+#             */
/*   Updated: 2020/10/26 14:36:35 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void	combi_init(t_combi **combi, t_fractal *fra, t_mouse *mouse)
{
	(*combi) = (t_combi *)malloc(sizeof(t_combi));
	(*combi)->fra = fra;
	(*combi)->mouse = mouse;
}

void	clean_screen(t_fractal *fra)
{
	int i;
	int h;
	int w;

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
}

void	fractal_init(t_fractal **fra, char *name, t_mouse **mouse)
{
	t_combi		*combi;

	combi = NULL;
	(*mouse) = (t_mouse *)malloc(sizeof(t_mouse));
	(*mouse)->mouse_x = 0.0;
	(*mouse)->mouse_y = 0.0;
	(*mouse)->mouse_disable = 0;
	(*fra) = (t_fractal *)malloc(sizeof(t_fractal));
	(*fra)->mlx_ptr = mlx_init();
	(*fra)->win_ptr = mlx_new_window((*fra)->mlx_ptr, WIDTH, HEIGHT, "Fractal");
	(*fra)->img_ptr = mlx_new_image((*fra)->mlx_ptr, WIDTH, HEIGHT);
	(*fra)->data_addr = mlx_get_data_addr((*fra)->img_ptr, \
				&((*fra)->bits_per_pixel), &((*fra)->size_line),\
						&((*fra)->endian));
	(*fra)->offset_x = 0;
	(*fra)->offset_y = 0;
	(*fra)->zoom = 1;
	(*fra)->choose_color = 1;
	(*fra)->maxiterate = 45;
	(*fra)->name = name;
	(*fra)->flame_p = 0;
	(*fra)->chaosgame_seed = 5;
	clean_screen(*fra);
	combi_init(&combi, *fra, *mouse);
	fractal_controls(combi);
}
