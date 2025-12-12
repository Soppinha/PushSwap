NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       utils.c \
       list_utils.c \
       list_find_utils.c \
       parse.c \
       sort_utils.c \
       operations_swap.c \
       operations_push.c \
       operations_rotate.c \
       operations_reverse.c \
       turk_init.c \
       turk_init_a.c \
       turk_init_b.c \
       turk_utils.c \
       turk_move.c \
       sort_turk.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re