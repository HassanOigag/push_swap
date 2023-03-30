/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 10:55:29 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/30 12:08:51 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	ascending(int a, int b)
{
	return (a > b);
}

static void	exit_quit(t_stacks *stacks, char *rule)
{
	free(rule);
	free_stack(&stacks->stack_a);
	free_stack(&stacks->stack_b);
	error_log();
}

static void	execute_rule(t_stacks *stacks, char *rule)
{
	if (ft_strncmp(rule, "pa\n", 3) == 0)
		pa(stacks);
	else if (ft_strncmp(rule, "pb\n", 3) == 0)
		pb(stacks);
	else if (ft_strncmp(rule, "sa\n", 3) == 0)
		sa(stacks);
	else if (ft_strncmp(rule, "sb\n", 3) == 0)
		sb(stacks);
	else if (ft_strncmp(rule, "ss\n", 3) == 0)
		ss(stacks);
	else if (ft_strncmp(rule, "ra\n", 3) == 0)
		ra(stacks);
	else if (ft_strncmp(rule, "rb\n", 3) == 0)
		rb(stacks);
	else if (ft_strncmp(rule, "rra\n", 4) == 0)
		rra(stacks);
	else if (ft_strncmp(rule, "rrb\n", 4) == 0)
		rrb(stacks);
	else if (ft_strncmp(rule, "rrr\n", 4) == 0)
		rrr(stacks);
	else
		exit_quit(stacks, rule);
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

int	main(int argc, char **argv)
{
	char		**args;
	t_stacks	stacks;
	char		*rule;

	if (argc == 1)
		return (0);
	args = get_args(argv + 1, argc - 1);
	init_stacks(&stacks, args);
	while (1)
	{
		rule = get_next_line(0);
		if (!rule)
		{
			if (is_stack_sorted(stacks.stack_a, ascending) && !stacks.stack_b)
				ft_printf("OK\n");
			else
				ft_printf("KO\n");
			break ;
		}
		execute_rule(&stacks, rule);
		free(rule);
	}
	free_stack(&stacks.stack_a);
	return (0);
}
