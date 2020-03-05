/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:39:07 by xtang             #+#    #+#             */
/*   Updated: 2020/03/04 17:39:13 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** "fractal.h" for terminate(),
** 
*/


#include "fractol.h"
#include "error_message.h"
#include <errno.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
    char    *frac_name;
	t_frac      *frac;

	errno = 0;
	if (argc == 2)
	{
        frac_name = argv[1];
        if (ft_strcmp(frac_name, "julia") != 0 &&
            ft_strcmp(argv[1], "mandelbrot") != 0 &&
            ft_strcmp(argv[1], "burningship") != 0)
                terminate(ERR_FRAC_NAME);
		frac = frac_init();
		draw(frac, frac_name);
		setup_controls(frac);
		mlx_loop(frac->mlx);
	}
	terminate(ERR_USAGE);
    return (0);
}