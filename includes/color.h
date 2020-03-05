/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:12:11 by xtang             #+#    #+#             */
/*   Updated: 2020/03/04 21:12:20 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E

typedef struct	s_color
{
	int decimal;
	int r;
	int g;
	int b;
}				t_color;

#endif