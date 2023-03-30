/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hoigag <hoigag@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 11:13:14 by hoigag            #+#    #+#             */
/*   Updated: 2023/03/30 12:06:57 by hoigag           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_log(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static void	exit_free(char **arr)
{
	free_args(arr);
	error_log();
}

long	ft_atoi_v2(const char *str, char **arr)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!str[i])
		free_quit();
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			freequit();
		res = res * 10 + (str[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			freequit();
		i++;
	}
	return (sign * res);
}

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

int	is_stack_sorted(t_node *stack, int (*comp)(int, int))
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->next)
	{
		if (comp(tmp->value, tmp->next->value))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
