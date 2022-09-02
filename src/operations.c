/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:34:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/02 14:15:34 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	swap(t_stack *stack)
{
	int	tmp;

	if (stack->end_index < 1)
		return (0);
	tmp = stack->array[stack->end_index];
	stack->array[stack->end_index] = stack->array[stack->end_index - 1];
	stack->array[stack->end_index - 1] = tmp;
	return (1);
}

int	rotate(t_stack *stack)
{
	if (is_empty(stack))
		return (0);
	unshift(stack, pop(stack));
	return (1);
}

int	reverse_rotate(t_stack *stack)
{
	if (is_empty(stack))
		return (0);
	push(stack, shift(stack));
	return (1);
}

int	push_from(t_stack *src_stack, t_stack *dest_stack)
{
	if (is_empty(src_stack) || is_full(dest_stack))
		return (0);
	push(dest_stack, pop(src_stack));
	return (1);
}

int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(operation, "SA", 2) == 0)
		return (swap(stack_a));
	if (ft_strncmp(operation, "SB", 2) == 0)
		return (swap(stack_b));
	if (ft_strncmp(operation, "SS", 2) == 0)
		return (swap(stack_a) && swap(stack_b));
	if (ft_strncmp(operation, "RRA", 3) == 0)
		return (reverse_rotate(stack_a));
	if (ft_strncmp(operation, "RRB", 3) == 0)
		return (reverse_rotate(stack_b));
	if (ft_strncmp(operation, "RRR", 3) == 0)
		return (reverse_rotate(stack_a) && reverse_rotate(stack_b));
	if (ft_strncmp(operation, "RA", 2) == 0)
		return (rotate(stack_a));
	if (ft_strncmp(operation, "RB", 2) == 0)
		return (rotate(stack_b));
	if (ft_strncmp(operation, "RR", 2) == 0)
		return (rotate(stack_a) && rotate(stack_b));
	if (ft_strncmp(operation, "PA", 2) == 0)
		return (push_from(stack_b, stack_a));
	if (ft_strncmp(operation, "PB", 2) == 0)
		return (push_from(stack_a, stack_b));
	return (0);
}
