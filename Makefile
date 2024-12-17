# * push_swap Makefile *

# Project name
NAME = push_swap
BONUSNAME = checker

# Compiling flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = push_swap.c \
	mainsort_phase3.c \
	mainsort.c \
	stack.c \
	simplesorts_utils.c \
	simplesorts.c \
	stack_ops_a.c \
	stack_ops_b.c \
	stacks_reindex.c \
	stacks.c \

# Bonus source files
SRCS_BONUS = checker_bonus.c \
	gnl_bonus.c \
	gnl_utils_bonus.c \
	parse_bonus.c \
	stack_bonus.c \
	stack_ops_a_bonus.c \
	stack_ops_b_bonus.c \
	stack_ops_both_bonus.c \
	stacks_bonus.c
	
# Object files
OBJS = $(SRCS:.c=.o)

# Bonus object files
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# Colors
RED	= "\033[0;31m"
GREEN = "\033[0;32m"
NO_COLOR = "\033[0m"

# Rules
all:$(NAME)

$(NAME):$(OBJS)
	@echo $(GREEN)Making $(NAME)$(NO_COLOR)
	cc $(CFLAGS) -o $(NAME) $(OBJS)

%.o:%.c
	@echo $(GREEN)Making object files$(NO_COLOR)
	cc $(CFLAGS) -o $@ -c $<

bonus:$(OBJS_BONUS)
	@echo $(GREEN)Making $(BONUSNAME) [Bonus] $(NO_COLOR)
	cc $(CFLAGS) -o $(BONUSNAME) $(OBJS_BONUS)

clean:
	@echo $(RED)Removing .o files$(NO_COLOR)
	rm -rf ${OBJS} ${OBJS_BONUS}

fclean: clean
	@echo $(RED)Removing $(NAME) $(NO_COLOR)
	rm -rf $(NAME) $(BONUSNAME)

re: fclean all

.PHONY: all clean fclean re bonus
