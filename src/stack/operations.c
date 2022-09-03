/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:34:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/03 16:28:20 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
