/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:50:23 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/31 20:39:35 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->value = value;
	node->next = 0;
	return (node);
}

void	push(t_node **top, int value)
{
	t_node	*new;

	new = new_node(value);
	if (!new)
		error_log();
	if (! *top)
		*top = new;
	else
	{
		new->next = *top;
		*top = new;
	}
}

t_node	*pop(t_node **top)
{
	t_node	*node;

	node = *top;
	if (!node)
		return (0);
	*top = node->next;
	node->next = 0;
	return (node);
}

void	print_stack(t_node *stack_a, t_node *stack_b)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = stack_a;
	tmp2 = stack_b;
	ft_printf("\n");
	while (tmp)
	{
		if (tmp2 && tmp)
			ft_printf("%d | %d\n", tmp->value, tmp2->value);
		else if (tmp)
			ft_printf("%d | \n", tmp->value);
		else if (tmp2)
			ft_printf("   | %d\n", tmp2->value);
		tmp = tmp->next;
		if (tmp2)
			tmp2 = tmp2->next;
	}
	ft_printf("-----\n");
	ft_printf("a | b\n");
}	

int	get_stack_length(t_node *stack)
{
	t_node	*tmp;
	int		size;

	tmp = stack;
	size = 0;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
