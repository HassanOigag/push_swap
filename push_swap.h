/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:44:40 by hoigag            #+#    #+#             */
/*   Updated: 2023/02/16 15:22:49 by hoigag           ###   ########.fr       */
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

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

//stack operation functions
t_node	*new_node(int value);
void	push(t_node **top, int value);
t_node	*pop(t_node **top);
void	print_stack(t_node *stack_a, t_node *stack_b);
int		get_stack_length(t_node *stack);

//helper functions
long	ft_atoi_v2(const char *str);
void	error_log(void);

int		check_for_duplicates(t_node *stack);

//checking arguments
t_node	*array_to_stack(char **arr);
// int		check_if_elem_in_stack(t_node *stack, int value);
// int		check_args(char **args, int n);	

//operations
char	**get_args(char **argv, int n);
void	swap(t_node *stack);
void	pop_and_push(t_node **b, t_node **a);
#endif