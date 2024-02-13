# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconti <aconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 15:10:20 by aconti            #+#    #+#              #
#    Updated: 2024/02/13 21:45:17 by aconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol
SRCS = bonus.c events.c init.c main.c math_utils.c other_utils.c render.c string_utils.c
OBJS = $(SRCS:.c=.o)
MLX = "https://github.com/42Paris/minilibx-linux.git"
MLX_DIR = minilibx-linux
FLAGS = -Lminilibx-linux -lmlx -lX11 -lXext
all: $(MLX_DIR) $(NAME)
$(MLX_DIR):
	@git clone $(MLX)
	@cd $(MLX_DIR) && ./configure
$(NAME): $(OBJS)
	cc -Wall -Wextra -Werror $(OBJS) $(FLAGS) -o $(NAME) -g
bonus: $(MLX_DIR)
	cc -Wall -Wextra -Werror  $(FLAGS) -o $(NAME)
clean:
	rm -f $(OBJS) 
fclean: clean
	rm -f $(NAME)
re: fclean all
