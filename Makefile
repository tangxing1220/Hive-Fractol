# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xtang <xtang@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/04 17:38:09 by xtang             #+#    #+#              #
#    Updated: 2020/11/03 13:34:21 by xtang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

FLAGS = -Wall -Werror -Wextra

INC_PATH = incl
SRC_PATH = srcs
OBJ_PATH = objs

SOURCES = main.c \
		assign_color.c \
		controls.c \
		change_color.c \
		frac_burningship.c \
		frac_julia.c \
		frac_mandelbrot.c \
		fractal_action.c \
		show_str.c \
		frac_chaosgame.c \
		frac_flame.c \
		frac_flame_a.c \
		frac_flame_b.c \
		frac_flame_c.c \
		frac_flame_d.c \
		frac_flame_e.c \
		fractal_init.c \
		show_str_flame.c

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

MLX = -I /usr/local/include -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit -lpthread

.PHONY: all libft tmp clean fclean re

all: libft tmp $(NAME)

$(NAME): $(OBJS)
	@echo "Object files are created in objs folder"
	@echo "$(NAME) is created"
	@gcc $(FLAGS) -o $@ $^ -L libft/ -lft -I $(INC_PATH)/ $(MLX)


$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c 
	@gcc $(FLAGS) -c -o $@ $< -I $(INC_PATH)/ -I libft/includes

libft:
	@make -C libft/

tmp:
	@mkdir	-p objs

clean:
	@echo "Delete object files in objs folder"
	@make clean -C libft/
	@rm -rf objs/

fclean: clean
	@echo "Delete $(NAME) file"
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean
	@$(MAKE) all
