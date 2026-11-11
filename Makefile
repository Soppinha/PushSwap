NAME		=	push_swap
NAME_BONUS	=	checker

# ********************************* OUTPUT ********************************** #

TAG			=	push_swap
RESET		=	\033[0m
C_TAG		=	\033[1;34m
C_BUILD		=	\033[0;32m
C_DONE		=	\033[1;32m
C_CLEAN		=	\033[0;33m
C_RM		=	\033[0;31m
LOG			=	printf "$(C_TAG)%-12s$(RESET) %b%-10s$(RESET) %s\n" "[$(TAG)]"
SUBMAKE		=	$(MAKE) -s --no-print-directory -C

# ********************************** BUILD ********************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

SRC_DIR		=	src
OBJ_DIR		=	obj
INC_DIR		=	includes

LIBFT_DIR	=	libft
LIBFT		=	$(LIBFT_DIR)/libft.a

INCLUDES	=	-I$(INC_DIR) -I$(LIBFT_DIR)/include
HEADERS		=	$(INC_DIR)/push_swap.h \
				$(INC_DIR)/checker_bonus.h

OPERATIONS	=	push.c reverse.c rotate.c swap.c

SORT		=	sort.c sort_cost.c sort_finish.c sort_init.c sort_move.c \
				sort_rotate.c sort_small.c sort_target.c sort_utils.c

STACK		=	stack.c stack_find.c stack_free.c stack_get.c stack_utils.c

UTILS		=	utils.c

CHECKER		=	checker_bonus.c checker_utils_bonus.c

COMMON		=	parse.c \
				$(addprefix operations/, $(OPERATIONS)) \
				$(addprefix sort/, $(SORT)) \
				$(addprefix stack/, $(STACK)) \
				$(addprefix utils/, $(UTILS))

SRCS		=	main.c $(COMMON)
SRCS_BONUS	=	$(COMMON) $(addprefix checker/, $(CHECKER))

OBJS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS	=	$(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@$(LOG) "$(C_DONE)" linked "$(NAME)"

bonus:		$(NAME_BONUS)

$(NAME_BONUS):	$(LIBFT) $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(NAME_BONUS)
	@$(LOG) "$(C_DONE)" linked "$(NAME_BONUS)"

$(LIBFT):
	@$(SUBMAKE) $(LIBFT_DIR)

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@$(LOG) "$(C_BUILD)" compiling "$<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(LOG) "$(C_CLEAN)" cleaned objects
	@$(SUBMAKE) $(LIBFT_DIR) clean

fclean:		clean
	@$(RM) $(NAME) $(NAME_BONUS)
	@$(LOG) "$(C_RM)" removed "$(NAME) $(NAME_BONUS)"
	@$(SUBMAKE) $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all bonus clean fclean re
