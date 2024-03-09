CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

CLIENT = ft_client.c
SERVER = ft_server.c

OBJ_CLIENT = $(CLIENT:.c=.o)
OBJ_SERVER = $(SERVER:.c=.o)

all: client server

client: $(OBJ_CLIENT)
	$(CC) $(CFLAGS) -o client $(OBJ_CLIENT)

server: $(OBJ_SERVER)
	$(CC) $(CFLAGS) -o server $(OBJ_SERVER)

.PHONY: clean

clean:
	rm -f client server $(OBJ_CLIENT) $(OBJ_SERVER)