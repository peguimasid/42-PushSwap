/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:20:40 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/03 19:46:05 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*create_stack(unsigned int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = size;
	stack->end_index = -1;
	stack->array = (int *)ft_calloc(size, sizeof(int));
	return (stack);
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->array);
	free(stack_b->array);
	free(stack_a);
	free(stack_b);
}
