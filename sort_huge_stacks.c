/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_huge_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:27:38 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/03 20:37:24 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index_in_sorted_array(int *sorted, int size, int n)
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

static void	range(t_stacks *stacks, int *sorted, int start, int end)
{
	int		size;
	int		top;
	int		index;

	size = get_stack_length(stacks->stack_a);
	while (get_stack_length(stacks->stack_a))
	{
		top = stacks->stack_a->value;
		index = get_index_in_sorted_array(sorted, size, top);
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
}

static void	best_move(t_stacks *stacks)
{
	int	middle;

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
}

static void	sort_reverse_sorted_stack(t_stacks *stacks)
{
	while (get_stack_length(stacks->stack_a))
	{
		rra(stacks);
		pb(stacks);
	}
	while (get_stack_length(stacks->stack_b))
		pa(stacks);
}

void	sort_big_numbers(t_stacks *stacks, int *sorted, int start, int end)
{
	if (is_stack_sorted(stacks->stack_a, descending))
		sort_reverse_sorted_stack(stacks);
	else
	{
		range(stacks, sorted, start, end);
		best_move(stacks);
	}
}
