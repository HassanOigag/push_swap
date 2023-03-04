/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:27:44 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/04 22:31:45 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (! *stack || get_stack_length(*stack) == 1)
		return ;
	first = pop(stack);
	second = pop(stack);
	push(stack, first);
	push(stack, second);
}

void	sa(t_stacks *stacks)
{
	swap(&stacks->stack_a);
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->stack_b);
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	swap(&stacks->stack_b);
}
