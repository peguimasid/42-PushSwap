/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:10:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 11:24:36 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		str++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

long	get_val(char *str)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
		result = result * 10 + str[i++] - '0';
	if (result > INT_MAX || result < INT_MIN)
		return (2147483648);
	return (result * sign);
}

int	fill_stack(t_stack *stack, char **av)
{
	int i = 0;
	long val;

	while (av[i])
	{
		if (!is_num(av[i]))
			return (0);
		val = get_val(av[i]);
		if (val == 2147483648 || includes(stack, val))
			return (0);
		push(stack, val);
		i++;
	}

	return (1);
}