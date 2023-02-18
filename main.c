/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:18:30 by hoigag            #+#    #+#             */
/*   Updated: 2023/02/18 18:49:03 by hoigag           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	// t_node	*stack_b;
	char	**args;

	if (argc == 1)
		return (0);
	// stack_b = 0;
	args = get_args(argv + 1, argc - 1);
	stack_a = array_to_stack(args);
	if (check_for_duplicates(stack_a))
		error_log();
	print_one_stack(stack_a);
	// if (check_for_duplicates(stack_a))
	// 	error_log();
	// print_stack(stack_a, stack_b);
	// pop_and_push(&stack_a, &stack_b);
	// ft_printf("%d\n", stack_b->value);
	// print_stack(stack_a, stack_b);
	return (0);
}
