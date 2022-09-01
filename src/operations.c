/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:34:14 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 11:44:59 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	operation_sa(t_stack *stack_a)
{
	int	tmp;

	if (stack_a->end_index < 1)
		return (0);
	tmp = stack_a->array[stack_a->end_index];
	stack_a->array[stack_a->end_index] = stack_a->array[stack_a->end_index - 1];
	stack_a->array[stack_a->end_index - 1] = tmp;
	return (1);
}

int	operation_sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->end_index < 1)
		return (0);
	tmp = stack_b->array[stack_b->end_index];
	stack_b->array[stack_b->end_index] = stack_b->array[stack_b->end_index - 1];
	stack_b->array[stack_b->end_index - 1] = tmp;
	return (1);
}

int	do_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(operation, "SA", 2) == 0)
		return (operation_sa(stack_a));
	if (ft_strncmp(operation, "SB", 2) == 0)
		return (operation_sb(stack_b));
	return (0);
}
