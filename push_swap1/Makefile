NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
RM			= rm -f
HEADER		= includes/push_swap.h

GREEN		= \033[0;32m
YELLOW		= \033[1;33m
RED			= \033[0;31m
BLUE		= \033[0;34m
RESET		= \033[0m

SRCS		= main.c					\
			  src/parse.c				\
			  src/utils/utils.c			\
			  src/utils/utils_split.c	\
			  src/operations/push.c		\
			  src/operations/reverse.c	\
			  src/operations/rotate.c	\
			  src/operations/swap.c		\
			  src/sort/sort_cost.c		\
			  src/sort/sort_finish.c	\
			  src/sort/sort_init.c		\
			  src/sort/sort_move.c		\
			  src/sort/sort_rotate.c	\
			  src/sort/sort_small.c		\
			  src/sort/sort_target.c	\
			  src/sort/sort_utils.c		\
			  src/sort/sort.c			\
			  src/stack/stack_find.c	\
			  src/stack/stack_free.c	\
			  src/stack/stack_get.c		\
			  src/stack/stack_utils.c	\
			  src/stack/stack.c			\

OBJS		= $(SRCS:.c=.o)

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