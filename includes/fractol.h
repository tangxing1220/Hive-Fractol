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

# define HEIGHT			800
# define WIDTH			800

typedef struct			s_mouse
{
	char				is_pressed;
	int					x;
	int					y;
	int					previous_x;
	int					previous_y;
}						t_mouse;

typedef struct			s_control
{
	double				offset_x;
	double				offset_y;
	double				zoom;
	int					select_color;
	int					maxIterate;
}						t_control;

typedef struct			s_zoom
{
	double				min;
	double				max;
	double				factor;
	int					count;
}						t_zoom;


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
	t_control			*control;
	t_zoom				*zoom;
}						t_frac;

t_frac					*frac_init(void);
void					draw(t_frac *frac,char *frac_name);
void					draw_julia(t_frac *frac);
void					draw_mandelbrot(t_frac *frac);
void					draw_burningship(t_frac *frac);
void					put_pixel(t_frac *frac, int x, int y, int color); 
int						get_color(t_frac *frac, double newRe, double newIm, int i);
void					terminate(char *s);
void					print_menu(t_frac *frac);

void					setup_controls(t_frac *fdf);	
int 					get_color_pattern(int color_index, double iter);	
int						mouse_move(int x, int y, void *param);
void					change_color(int key, t_frac *frac);
void					zoom(int key, t_frac *frac);
void					move(int key, t_frac *frac);

#endif
