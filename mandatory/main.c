/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:18:30 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/30 12:03:03 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_log(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	init_stacks(t_stacks *stacks, char **args)
{
	stacks->stack_b = 0;
	stacks->stack_a = array_to_stack(args);
	if (check_for_duplicates(stacks->stack_a))
	{
		free_stack(&stacks->stack_a);
		error_log();
	}
}

static void	sort(t_stacks *stacks, int *sorted_tab)
{
	int	length;

	length = get_stack_length(stacks->stack_a);
	if (length == 2)
		sa(stacks);
	else if (length == 3)
		sort_3_numbers(stacks);
	else if (length <= 5)
		sort_5_numbers(stacks);
	else if (length <= 100)
		sort_big_numbers(stacks, sorted_tab, 0, 15);
	else
		sort_big_numbers(stacks, sorted_tab, 0, 30);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**args;
	int			*sorted_tab;

	if (argc == 1)
		return (0);
	args = get_args(argv + 1, argc - 1);
	init_stacks(&stacks, args);
	if (is_stack_sorted(stacks.stack_a, ascending))
	{
		free_stack(&stacks.stack_a);
		return (0);
	}
	sorted_tab = get_sorted_array(argv + 1, argc - 1);
	sort(&stacks, sorted_tab);
	free(sorted_tab);
	free_stack(&stacks.stack_a);
	return (0);
}
