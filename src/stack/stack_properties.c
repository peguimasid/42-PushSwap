/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_properties.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:23:52 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/02 20:53:44 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_empty(t_stack *stack)
{
	return (stack->end_index == -1);
}

int	is_full(t_stack *stack)
{
	return (stack->end_index == stack->size - 1);
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
