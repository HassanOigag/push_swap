/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:07:58 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/04 23:35:01 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../my_libs/libft/libft.h"
# include "../my_libs/printf/ft_printf.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
	t_node	*stack_a;
	t_node	*stack_b;

}	t_stacks;

char	*get_next_line(int fd);
t_node	*new_node(int value);
void	push(t_node **top, t_node *new);
t_node	*pop(t_node **top);
long	ft_atoi_v2(const char *str, char **arr);
void	error_log(void);
void	free_args(char **args);
t_node	*array_to_stack(char **arr);
char	**get_args(char **argv, int n);
int		check_for_duplicates(t_node *stack);
int		is_stack_sorted(t_node *stack, int (*comp)(int, int));
int		get_stack_length(t_node *stack);
void	free_stack(t_node **stack);
//* rules
void	rotate(t_node **stack);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks	*stacks);
void	rb(t_stacks	*stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
#endif