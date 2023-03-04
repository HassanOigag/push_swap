CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = push_swap
SRCS = mandatory/main.c mandatory/stack_utils.c mandatory/helper_functions.c mandatory/check_args.c \
	mandatory/rules.c mandatory/rules2.c mandatory/rules3.c mandatory/push_swap.c mandatory/bubble_sort.c mandatory/sort_huge_stacks.c
OBJS = $(SRCS:.c=.o)

BONUS_NAME = checker
BONUS_SRCS = bonus/checker.c bonus/check_args_bonus.c bonus/get_next_line.c bonus/helper_functions_bonus.c bonus/stack_utils_bonus.c \
		bonus/rules_bonus.c bonus/rules2_bonus.c bonus/rules3_bonus.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus: $(BONUS_NAME)

$(NAME) : $(OBJS)
	@make -C ./my_libs/printf all
	@make -C ./my_libs/libft all
	$(CC) $(CFLAGS) $^ -L./my_libs/libft -lft -L./my_libs/printf -lftprintf -o $@

$(BONUS_NAME) : $(BONUS_OBJS)
	@make -C ./my_libs/printf all
	@make -C ./my_libs/libft all
	$(CC) $(CFLAGS) $^ -L./my_libs/libft -lft -L./my_libs/printf -lftprintf -o $@

clean : 
	make -C ./my_libs/printf clean
	make -C ./my_libs/libft clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean : clean
	make -C ./my_libs/printf fclean
	make -C ./my_libs/libft fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re : fclean all

.PHONY: all re clean fclean bonus
