/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:56:55 by hoigag            #+#    #+#             */
/*   Updated: 2023/02/27 17:07:48 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	sort_3_numbers(t_stacks *stacks)
{
	int	min;
	int	max;

	min = get_min(stacks->stack_a);
	max = get_max(stacks->stack_a);
	if (stacks->stack_a->next->value == min
		&& stacks->stack_a->next->next->value == max)
		sa(stacks);
	else if (stacks->stack_a->value == max
		&& stacks->stack_a->next->next->value == min)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (stacks->stack_a->value == max
		&& stacks->stack_a->next->value == min)
		ra(stacks);
	else if (stacks->stack_a->value == min
		&& stacks->stack_a->next->value == max)
	{
		sa(stacks);
		ra(stacks);
	}
	else
		rra(stacks);
}

void	sort_5_numbers(t_stacks *stacks)
{
	int	min_index;

	while (get_stack_length(stacks->stack_a) != 3)
	{
		min_index = get_min_index(stacks->stack_a);
		if (min_index == 0)
			pb(stacks);
		else if (min_index >= 2)
			rra(stacks);
		else if (min_index < 2)
			sa(stacks);
	}
	if (!is_stack_sorted(stacks->stack_a))
		sort_3_numbers(stacks);
	pa(stacks);
	pa(stacks);
}

void	sort_100_numbers(t_stacks *stacks)
{
	int	min_index;
	int	middle;

	while (stacks->stack_a)
	{
		min_index = get_min_index(stacks->stack_a);
		middle = get_stack_length(stacks->stack_a) / 2;
		if (min_index == 0)
			pb(stacks);
		else if (min_index >= middle)
			rra(stacks);
		else if (min_index < middle)
			ra(stacks);
	}
	while (stacks->stack_b)
		pa(stacks);
}
