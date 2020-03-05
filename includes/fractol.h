/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:49:32 by xtang             #+#    #+#             */
/*   Updated: 2020/03/04 17:49:35 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# define HEIGHT			1080
# define WIDTH			1920
# define MENU_WIDTH		250

typedef struct			s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct			s_frac
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	t_mouse				*mouse;
}						t_frac;

t_frac					*frac_init(void);
void					draw(t_frac *frac, char *frac_name);
void					draw_julia(t_frac *frac);
void					draw_mandelbrot(t_frac *frac);
void					draw_burningship(t_frac *frac);
void					put_pixel(t_frac *frac, int x, int y, int color); 
int						get_color(int i);

#endif
