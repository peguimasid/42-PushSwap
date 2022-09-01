/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:23:52 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 18:24:26 by gmasid           ###   ########.fr       */
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

void	push(t_stack *stack, int value)
{
	if (stack->end_index + 1 >= stack->size)
		return ;
	stack->array[++stack->end_index] = value;
}

int	pop(t_stack *stack)
{
	int	removed_node;

	removed_node = stack->array[stack->end_index];
	stack->array[stack->end_index--] = 0;
	return (removed_node);
}

void	unshift(t_stack *stack, int value)
{
	int	i;

	i = ++stack->end_index;
	while (i >= 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = value;
}

int	shift(t_stack *stack)
{
	int	i;
	int	remove_node;

	remove_node = stack->array[0];
	i = 1;
	while (i <= stack->end_index)
	{
		stack->array[i - 1] = stack->array[i];
		i++;
	}
	stack->array[stack->end_index--] = 0;
	return (remove_node);
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
