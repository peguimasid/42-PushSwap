/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 19:20:40 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/02 20:52:18 by gmasid           ###   ########.fr       */
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

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}
