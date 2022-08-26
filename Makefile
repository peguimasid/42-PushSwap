NAME=push_swap
CC=cc

SRCS	= src/push_swap.c

LIBFTPRINTF = lib/ft_printf/libftprintf.a

OBJ	= $(SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -s -C lib/ft_printf
	$(CC) $(OBJ) -o $(NAME) $(LIBFTPRINTF)

all: $(NAME)

clean:
	make clean -s -C lib/ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -s -C lib/ft_printf
	rm -rf $(NAME)

re:	fclean all

.PHONY:	all clean fclean re