/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_methods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:25:09 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/02 20:53:55 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Insert element in top of stack
void	push(t_stack *stack, int value)
{
	if (is_full(stack))
		return ;
	stack->array[++stack->end_index] = value;
}

// Remove element from top of stack and return it
int	pop(t_stack *stack)
{
	int	removed_node;

	removed_node = stack->array[stack->end_index];
	stack->array[stack->end_index--] = 0;
	return (removed_node);
}

// Insert element in beginning of stack
void	unshift(t_stack *stack, int value)
{
	int	i;

	if (is_full(stack))
		return ;
	i = ++stack->end_index;
	while (i >= 0)
	{
		stack->array[i] = stack->array[i - 1];
		i--;
	}
	stack->array[0] = value;
}

// Remove element from beginning of stack and return it
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

// Return element at Nth position of stack, counting from top to bottom
int	peek(t_stack *stack, int i)
{
	return (stack->array[stack->end_index - i]);
}
