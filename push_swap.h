/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:44:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/02/18 23:42:46 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <limits.h>
//* structs
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

//*stack operation functions
t_node	*new_node(int value);
void	push(t_node **top, t_node *new);
t_node	*pop(t_node **top);
void	print_stack(t_stacks *stack_a);
int		get_stack_length(t_node *stack);
void	print_one_stack(t_node *stack);

//*helper functions
long	ft_atoi_v2(const char *str);
void	error_log(void);
void	free_args(char **args);

//*checking arguments
t_node	*array_to_stack(char **arr);
char	**get_args(char **argv, int n);
int		check_for_duplicates(t_node *stack);

//*operations
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	ra(t_stacks	*stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
// void	pop_and_push(t_node **b, t_node **a);
#endif