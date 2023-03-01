/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:56:55 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/01 20:49:49 by hoigag           ###   ########.fr       */
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

void	sort_100_numbers(t_stacks *stacks, int *sorted_array)
{
	int	size;
	int	magic;
	int	magic_index;
	int	i;
	int	middle;
	int range;

	i = 1;
	range = 4;
	size = get_stack_length(stacks->stack_a);
	while (i <= range - 1)
	{
		magic_index = (size / range) * i;
		magic = sorted_array[magic_index];
		while (get_stack_length(stacks->stack_b) != magic_index + 1)
		{
			if (stacks->stack_a->value <= magic)
				pb(stacks);
			else
				ra(stacks);
		}
		i++;
	}
	i = 0;
	while (stacks->stack_a)
	{
		middle = get_stack_length(stacks->stack_a) / 2;
		if (stacks->stack_a->value == get_min(stacks->stack_a))
			pb(stacks);
		else if (get_min_index(stacks->stack_a) >= middle)
			rra(stacks);
		else
			ra(stacks);
	}

	while (stacks->stack_b)
	{
		middle = get_stack_length(stacks->stack_b) / 2;
		if (stacks->stack_b->value == get_max(stacks->stack_b))
			pa(stacks);
		else if (get_max_index(stacks->stack_a) >= middle)
			rrb(stacks);
		else
			rb(stacks);
	}
	// print_one_stack(stacks->stack_a);
}
	