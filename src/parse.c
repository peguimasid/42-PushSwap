/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:10:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/31 18:44:22 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(unsigned int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = size;
	stack->end_index = -1;
	stack->array = (int *)ft_calloc(size, sizeof(int));
	return (stack);
}

int	is_empty(t_stack *stack)
{
	return (stack->end_index == -1);
}

void	push(t_stack *stack, int item)
{
	if (stack->end_index + 1 >= stack->size)
		return ;
	stack->array[++stack->end_index] = item;
}

int	pop(t_stack *stack)
{
	int	removed_node;

	removed_node = stack->array[stack->end_index];
	stack->array[stack->end_index--] = 0;
	return (removed_node);
}

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

int	includes(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (i <= stack->end_index)
	{
		if (stack->array[i] == value)
			return (1);
		i++;
	}
	return (0);
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