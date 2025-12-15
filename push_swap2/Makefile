NAME		= push_swap

CC		= cc
CFLAGS		= -Wall -Wextra -Werror
RM		= rm -f

GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED		= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

SRCS		= main.c \
			  parse.c \
			  utils.c \
			  list_utils.c \
			  list_find_utils.c \
			  operations_push.c \
			  operations_swap.c \
			  operations_rotate.c \
			  operations_reverse.c \
			  sort_utils.c \
			  sort_turk.c \
			  turk_init.c \
			  turk_init_a.c \
			  turk_init_b.c \
			  turk_move.c \
			  turk_utils.c


OBJS		= $(SRCS:.c=.o)

HEADER		= push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Linkando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compilado com sucesso!$(RESET)"

%.o: %.c $(HEADER)
	@echo "$(BLUE)Compilando $<$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(YELLOW)Apagando objetos...$(RESET)"
	@$(RM) $(OBJS)
	@echo "$(GREEN)✓ Objetos removidos!$(RESET)"

fclean: clean
	@echo "$(YELLOW)Apagando $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@echo "$(GREEN)✓ Limpeza completa!$(RESET)"

# Recompilação
re: fclean all

# Phony targets
.PHONY: all clean fclean re