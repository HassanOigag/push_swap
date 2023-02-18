/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 22:14:47 by hoigag            #+#    #+#             */
/*   Updated: 2023/02/18 23:07:56 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{	
	t_node	*top;

	if (!stacks->stack_b)
		return ;
	top = pop(&stacks->stack_b);
	push(&stacks->stack_a, top);
	ft_printf("pa\n");
}

void	pb(t_stacks *stacks)
{	
	t_node	*top;

	if (!stacks->stack_a)
		return ;
	top = pop(&stacks->stack_a);
	push(&stacks->stack_b, top);
	ft_printf("pb\n");
}

void	rotate(t_node **stack)
{
	t_node	*top;
	t_node	*tmp;

	if (! *stack)
		return ;
	top = pop(stack);
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = top;
}

void	ra(t_stacks	*stacks)
{
	rotate(&stacks->stack_a);
	ft_printf("ra\n");
}

void	rb(t_stacks	*stacks)
{
	rotate(&stacks->stack_b);
	ft_printf("rb\n");
}

void	rr(t_stacks *stacks)
{	
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
	ft_printf("rr\n");
}
	