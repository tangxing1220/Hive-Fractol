/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:08:22 by xtang             #+#    #+#             */
/*   Updated: 2020/03/04 21:08:27 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "fractol.h"
#include "libft.h"
#include "mlx.h"
#include "error_message.h"
#include "stdio.h"


static void	draw_background(t_frac *frac)
{
	int	*image;
	int	i;

	ft_bzero(frac->data_addr, WIDTH * HEIGHT * (frac->bits_per_pixel / 8));
	image = (int *)(frac->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
//		image[i] = (i % WIDTH < MENU_WIDTH) ? MENU_BACKGROUND : BACKGROUND;
		image[i] = BACKGROUND;
		i++;
	}
}


void		draw(t_frac *frac, char *frac_name)
{
	
	draw_background(frac);
    
	if (ft_strcmp(frac_name, "julia") == 0)
		draw_julia(frac);
	if (ft_strcmp(frac_name, "mandelbrot") == 0)
		draw_mandelbrot(frac);
//	if (ft_strcmp(frac_name, "burningship"))
//		draw_burningship(frac);
	mlx_put_image_to_window(frac->mlx, frac->win, frac->img, 0, 0);
//	print_menu(frac);
}
