gcc -g -o fractol ./sources/main.c ./sources/utils.c ./sources/color.c ./sources/draw.c ./sources/init.c ./sources/julia.c ./sources/control.c -I./includes/ -I./minilibX/includes/ -I./libft/includes/ -L./libft/ -L./minilibX/ -lft -lmlx -lm -framework OpenGL -framework AppKit
