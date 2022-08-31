/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:10:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/31 18:21:07 by gmasid           ###   ########.fr       */
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
