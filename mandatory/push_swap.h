/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:44:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/04 23:39:22 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../my_libs/printf/ft_printf.h"
# include "../my_libs/libft/libft.h"
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
void	print_stacks(t_stacks *stack_a);
int		get_stack_length(t_node *stack);
void	print_one_stack(t_node *stack);
int		is_stack_sorted(t_node *stack, int (*comp)(int, int));

//*helper functions
long	ft_atoi_v2(const char *str);
void	error_log(void);
void	free_args(char **args);
int		get_max(t_node *stack);
int		get_min(t_node *stack);
int		get_max_index(t_node *stack);
int		get_min_index(t_node *stack);

//*checking arguments
t_node	*array_to_stack(char **arr);
char	**get_args(char **argv, int n);
int		check_for_duplicates(t_node *stack);

//*rules
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

//*sorting functions
void	sort_3_numbers(t_stacks *stacks);
void	sort_5_numbers(t_stacks *stacks);
void	sort_big_numbers(t_stacks *stacks, int *sorted, int start, int end);
int		*get_sorted_array(char **argv, int size);
int		ascending(int a, int b);
int		descending(int a, int b);
#endif