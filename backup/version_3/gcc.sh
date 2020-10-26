make -C libft/ fclean && make -C libft/
gcc -Werror -Wall -Wextra -g -o fractol ./srcs/fractal_action.c ./srcs/controls.c  ./srcs/main.c ./srcs/color.c ./srcs/draw_pixel.c ./srcs/burningship.c  ./srcs/julia.c  ./srcs/mandelbrot.c -L ./libft -lft -I ./libft/includes -I /usr/local/include -I ./incl/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
