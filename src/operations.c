/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:34:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 17:00:19 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	shift(stack);
}

int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(operation, "SA", 2) == 0)
		return (swap(stack_a));
	if (ft_strncmp(operation, "SB", 2) == 0)
		return (swap(stack_b));
	if (ft_strncmp(operation, "SS", 2) == 0)
		return (swap(stack_a) && swap(stack_b));
	if (ft_strncmp(operation, "RA", 2) == 0)
		return (rotate(stack_a));
	return (0);
}
