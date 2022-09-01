/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:34:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 16:56:25 by gmasid           ###   ########.fr       */
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
	int	i;
	int	tmp;

	if (is_empty(stack))
		return (0);
	tmp = stack->array[0];
	i = 1;
	while (i <= stack->end_index)
	{
		stack->array[i - 1] = stack->array[i];
		i++;
	}
	stack->array[i - 1] = tmp;
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
	if (ft_strncmp(operation, "RA", 2) == 0)
		return (rotate(stack_a));
	return (0);
}
