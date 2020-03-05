/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 20:16:15 by xtang             #+#    #+#             */
/*   Updated: 2020/03/04 20:17:33 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "error_message.h"
#include "mlx.h"
#include "libft.h"

t_frac		*frac_init(void)
{
	t_frac	*frac;

	if (!(frac = (t_frac *)ft_memalloc(sizeof(t_frac))))
		terminate(ERR_FRAC_INIT);
	if (!(frac->mlx = mlx_init()))
		terminate(ERR_FRAC_INIT);
	if (!(frac->win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "Fractol")))
		terminate(ERR_FRAC_INIT);
	if (!(frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT)))
		terminate(ERR_FRAC_INIT);
	frac->data_addr = mlx_get_data_addr(frac->img, &(frac->bits_per_pixel),
										&(frac->size_line), &(frac->endian));
	if (!(frac->mouse = (t_mouse *)ft_memalloc(sizeof(t_mouse))))
		terminate(ERR_FRAC_INIT);
	return (frac);
}
