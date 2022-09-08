NAME=push_swap
BONUS_NAME=checker
CC=cc

SRCS	= src/push_swap.c	\
				src/common.c	\
				src/parse/main.c	\
				src/parse/utils.c	\
				src/sort/main.c	\
				src/stack/create.c	\
				src/stack/methods.c	\
				src/stack/operations_controller.c	\
				src/stack/operations.c	\
				src/stack/properties.c	\

BONUS_SRCS	= src/checker.c	\
							src/common.c	\
							src/parse/main.c	\
							src/parse/utils.c	\
							src/sort/main.c	\
							src/stack/create.c	\
							src/stack/methods.c	\
							src/stack/operations_controller.c	\
							src/stack/operations.c	\
							src/stack/properties.c	\
							lib/get_next_line/get_next_line.c	\
							lib/get_next_line/get_next_line_utils.c	\

LIBFTPRINTF = lib/ft_printf/libftprintf.a

OBJ	= $(SRCS:.c=.o)
BONUS_OBJ	= $(BONUS_SRCS:.c=.o)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

$(NAME): $(OBJ)
	make -s -C lib/ft_printf
	$(CC) $(OBJ) -o $(NAME) $(LIBFTPRINTF)

$(BONUS_NAME): $(BONUS_OBJ)
	make -s -C lib/ft_printf
	$(CC) $(BONUS_OBJ) -o $(BONUS_NAME) $(LIBFTPRINTF)

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	make clean -s -C lib/ft_printf
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	make fclean -s -C lib/ft_printf
	rm -rf $(NAME) $(BONUS_NAME)

re:	fclean all

.PHONY:	all clean fclean re