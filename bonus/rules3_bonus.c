/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 22:27:29 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/04 22:31:33 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rr(t_stacks *stacks)
{	
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
}

void	reverse_rotate(t_node **stack)
{
	t_node	*tmp;
	t_node	*last;

	if (! *stack || get_stack_length(*stack) == 1)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = 0;
	push(stack, last);
}

void	rra(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
}

void	rrb(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_b);
}

void	rrr(t_stacks *stacks)
{
	reverse_rotate(&stacks->stack_a);
	reverse_rotate(&stacks->stack_b);
}
