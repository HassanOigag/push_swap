/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:18:30 by hoigag            #+#    #+#             */
/*   Updated: 2023/02/20 18:40:48 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_one_stack(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp)
	{
		ft_printf("%d\n", tmp->value);
		tmp = tmp -> next;
	}
}

static void	init_stacks(t_stacks *stacks, char **args)
{
	stacks->stack_b = 0;
	stacks->stack_a = array_to_stack(args);
	if (check_for_duplicates(stacks->stack_a))
		error_log();
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**args;

	if (argc == 1)
		return (0);
	args = get_args(argv + 1, argc - 1);
	init_stacks(&stacks, args);
	if (is_stack_sorted(stacks.stack_a))
		return (0);
	print_stacks(&stacks);
	if (get_stack_length(stacks.stack_a) == 2 && stacks.stack_a->value == get_max(stacks.stack_a))
		sa(&stacks);
	else if (get_stack_length(stacks.stack_a) == 3)
		sort_3_numbers(&stacks);
	print_stacks(&stacks);
	return (0);
}
