CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = push_swap
SRCS = main.c stack_utils.c helper_functions.c check_args.c rules.c rules2.c rules3.c push_swap.c bubble_sort.c
OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^
	
all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./printf all
	make -C ./libft all
	$(CC) $(CFLAGS) $^ -L./libft -lft -L./printf -lftprintf -o $@

clean : 
	make -C ./printf clean
	make -C ./libft clean
	rm -f $(OBJS)

fclean : clean
	make -C ./printf fclean
	make -C ./libft fclean
	rm -f $(NAME)

re : fclean all
