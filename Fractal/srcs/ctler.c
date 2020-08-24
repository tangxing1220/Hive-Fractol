/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctler.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 18:42:24 by xtang             #+#    #+#             */
/*   Updated: 2020/08/22 18:42:26 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fractal.h"

void ctler_init(t_ctler **ctler)
{
    (*ctler) = (t_ctler *)malloc(sizeof(t_ctler));
    (*ctler)->offset_x = 0;
    (*ctler)->offset_y = 0;
    (*ctler)->zoom = 1;
    (*ctler)->choose_color = 1;
    (*ctler)->maxIterate = 50;
}
