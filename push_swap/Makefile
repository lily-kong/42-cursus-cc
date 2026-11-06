NAME 	= push_swap
CC		= cc
CFLAGS 	= -Wall -Wextra -Werror
SRCS	= main.c \
		utils_of_string.c utils_of_stack.c utils_of_print.c \
		do_push.c do_swap.c do_rotate.c do_rrotate.c \
		parse_input.c parse_disorder.c parse_strategy.c parse_bench.c \
		sort_of_simple.c sort_of_medium.c sort_of_complex.c \

HEADER 	= push_swap.h
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	${CC} ${CFLAGS} -o $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re test