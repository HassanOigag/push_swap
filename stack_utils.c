/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:50:23 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/29 15:20:33 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	error_log(void)
{
	ft_putstr("Error\n");
	exit(1);
}

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

void	print_stck(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	if (!tmp)
	{
		printf("empty stack\n");
		return ;
	}
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	printf("stack\n");
}
