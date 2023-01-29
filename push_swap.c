/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:18:30 by hoigag            #+#    #+#             */
/*   Updated: 2023/01/29 15:54:11 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "string.h"

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_str_digits(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!is_digit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_if_args_are_valid_intgers(char **args, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (!is_str_digits(args[i]))
			error_log();
		i++;
	}
}

void	check_for_duplicates(char **args, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (strcmp(args[i], args[j]) == 0)
				error_log();
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	char	**args;

	if (argc == 1)
		return (0);
	args = argv + 1;
	check_if_args_are_valid_intgers(args, argc - 1);
	check_for_duplicates(args, argc - 1);
	stack_a = 0;
	print_stck(stack_a);
	return (0);
}
