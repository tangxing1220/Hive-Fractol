/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/22 12:37:15 by xtang             #+#    #+#             */
/*   Updated: 2020/09/04 17:18:45 by xtang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <math.h>
# include <pthread.h>
# include "../libft/includes/libft.h"
# include "mlx.h"
# include <stdio.h>

# define THREAD_NB			10
# define TXT_COL			0xFFFFFF

# define WIDTH				1920
# define HEIGHT				1080

# define MAIN_1				18
# define MAIN_2				19
# define MAIN_3				20
# define MAIN_4				21
# define MAIN_5				23
# define MAIN_6				22
# define MAIN_7				26

# define MAIN_ESC			53
# define MAIN_R				15
# define MAIN_M				46
# define MAIN_MINUS			27
# define MAIN_PLUS			24
# define MAIN_SPC			49

# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define ARROW_DOWN			125
# define ARROW_UP			126

# define M_SCROLL_UP		4
# define M_SCROLL_DOWN		5

# define NUM_F				6
# define SAMPLES			100000
# define FLAME_ITERATE		1500
# define SYMMETRY			2
# define GAMMA				2.2

typedef struct	s_fractal
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	char		*name;
	double		offset_x;
	double		offset_y;
	double		zoom;
	int			choose_color;
	int			maxiterate;
	int			flame_p;
	int			chaosgame_seed;
}				t_fractal;

typedef struct	s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct	s_complex_plain
{
	t_complex	max;
	t_complex	min;
	t_complex	offset;
	t_complex	factor;
}				t_complex_plain;

typedef struct	s_mouse
{
	double		mouse_x;
	double		mouse_y;
	int			mouse_disable;
}				t_mouse;

typedef struct	s_combi
{
	t_fractal	*fra;
	t_mouse		*mouse;
}				t_combi;

typedef struct	s_multi_th
{
	t_fractal	*fra;
	t_mouse		*mouse;
	int			th_height;
	int			th_sample;
}				t_multi_th;

typedef struct	s_flame_co
{
	double	a;
	double	b;
	double	c;
	double	d;
	double	e;
	double	f;
	int		red;
	int		green;
	int		blue;
}				t_flame_co;

typedef	struct	s_f_pixel
{
	unsigned int	counter;
	float			normal;
	int				r;
	int				g;
	int				b;
}				t_f_pixel;

typedef	struct	s_seed
{
	int		x;
	int		y;
}				t_seed;

void			combi_init(t_combi **combi, t_fractal *fra, t_mouse *mouse);
void			iteration_change(int key, t_combi *combi);
void			draw_pixel(t_fractal *fra, int x, int y, int col);
void			show_str_in_image(t_fractal *fra);
void			print_usage(void);

void			draw_burningship(t_fractal *fra);
void			draw_julia(t_fractal *fra, t_mouse *mouse);
void			draw_mandelbrot(t_fractal *fra);
void			draw_flame(t_fractal *fra);
void			draw_chaosgame(t_fractal *fra);

int				assign_color(double newre, double newim, int i,\
								t_fractal *fra);
void			change_color(t_fractal *fra, t_mouse *mouse);
void			color_pattern(int key, t_combi *combi);
void			flame_pattern(int key, t_combi *combi);
void			chaosgame_pattern(int key, t_combi *combi);

void			fractal_controls(t_combi *combi);
void			fractal_move(int key, t_combi *combi);
void			fractal_zoom(int button, t_combi *combi);
void			fractal_reset(t_combi *combi);
void			fractal_redraw(t_combi *combi);
void			clean_screen(t_fractal *fra);

#endif
