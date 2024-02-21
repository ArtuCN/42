CC = gcc

DEBUG_FLAGS = -g

SRC_DIRS = libft
SRC = main.c events.c \
		$(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJ = $(SRC:.c=.o)

n