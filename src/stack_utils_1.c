/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:23:52 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 20:29:21 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

// Check if stack contains determinate value
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
