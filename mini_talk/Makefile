CC := gcc
CFLAGS := -Wall -Wextra -Werror -g

CLIENT := client
SERVER := server

SRC_SERVER := ft_server.c ft_utils.c
SRC_CLIENT := ft_client.c ft_utils.c


INCLUDES := -I. -Ilibft

LIBFT := ./libft/libft.a
LIBFT_PATH := ./libft

all : $(SERVER) $(CLIENT)

$(SERVER): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) $(LIBFT) -o $(CLIENT)

$(LIBFT): $(shell make -C $(LIBFT_PATH) -q libft.a)
	make -C $(LIBFT_PATH)

clean:
	rm -f *.o

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

