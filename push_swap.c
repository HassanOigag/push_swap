/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:56:55 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/03 16:04:50 by hoigag           ###   ########.fr       */
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

int	get_index_in_sorted_array(int *sorted, int size, int n)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted[i] == n)
			break ;
		i++;
	}
	return (i);
}

void	sort_big_numbers(t_stacks *stacks, int *sorted_array, int start, int end)
{
	int		size;
	int		top;
	int		index;

	size = get_stack_length(stacks->stack_a);
	while (get_stack_length(stacks->stack_a))
	{
		top = stacks->stack_a->value;
		index = get_index_in_sorted_array(sorted_array, size, top);
		if (index >= start && index <= end)
		{
			pb(stacks);
			start++;
			end++;
		}
		else if (index > end)
			ra(stacks);
		else
		{
			pb(stacks);
			rb(stacks);
			start++;
			end++;
		}
	}
	int middle;
	middle = 0;
	while (get_stack_length(stacks->stack_b))
	{
		middle = get_stack_length(stacks->stack_b) / 2;
		if (stacks->stack_b->value == get_max(stacks->stack_b))
			pa(stacks);
		else if (get_max_index(stacks->stack_b) > middle)
			rrb(stacks);
		else
			rb(stacks);
	}
	// print_one_stack(stacks->stack_a);
}
	