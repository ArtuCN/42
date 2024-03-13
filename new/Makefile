CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

CLIENT = ft_client.c
SERVER = ft_server.c
UTILS = ft_utils_client.c ft_utils_server.c 

OBJ_CLIENT = $(CLIENT:.c=.o)
OBJ_SERVER = $(SERVER:.c=.o)
OBJ_UTILS = $(UTILS:.c=.o)

all: client server

client: $(OBJ_CLIENT) $(OBJ_UTILS)
	$(CC) $(CFLAGS) -o client $(OBJ_CLIENT) $(OBJ_UTILS)

server: $(OBJ_SERVER) $(OBJ_UTILS)
	$(CC) $(CFLAGS) -o server $(OBJ_SERVER) $(OBJ_UTILS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm -f  $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_UTILS)

fclean: clean
	rm -f client server $(OBJ_CLIENT) $(OBJ_SERVER)

re: fclean all

