/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:23:15 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/31 20:34:26 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node *stack)
{
	int		tmp;
	t_node	*next;

	if (!stack || get_stack_length(stack))
		return ;
	next = stack->next;
	tmp = stack->value;
	stack->value = next->value;
	next->value = tmp;
}

void	pop_and_push(t_node **b, t_node **a)
{
	t_node	*node;

	if (! *b)
		return ;
	node = pop(b);
	ft_printf("poped : %d\n", node->value);
	push(a, node->value);
	free(node);
}
