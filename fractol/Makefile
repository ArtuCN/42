# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconti <aconti@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 15:34:14 by aconti            #+#    #+#              #
#    Updated: 2024/01/12 16:58:39 by aconti           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
#CFLAGS = -Wall -Wextra -Werror
LIBS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

SRC = main.c events.c math_utils.c render.c string_utils.c init.c
OBJ = $(SRC:.c=.o)

NAME = fractal

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
