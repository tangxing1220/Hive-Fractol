make -C libft/ fclean && make -C libft/
gcc -Werror -Wall -Wextra -g -o fractol ./srcs/main.c ./srcs/color.c ./srcs/draw_pixel.c ./srcs/burningship.c  ./srcs/julia.c  ./srcs/mandelbrot.c  ./srcs/ctler.c -L ./libft -lft -I ./libft/includes -I /usr/local/include -I ./incl/ -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
