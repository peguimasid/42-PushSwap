/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:00:34 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/06 20:23:35 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->end_index + 1;
	while (--i > 0)
		if (stack->array[i] > stack->array[i - 1])
			return (0);
	return (1);
}

void	sort_big_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = stack_a->end_index;
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j <= len)
		{
			if (((peek(stack_a, 0) >> i) & 1) == 1)
				dispatch_operation(RA, stack_a, stack_b);
			else
				dispatch_operation(PB, stack_a, stack_b);
			j++;
		}
		while (stack_b->end_index >= 0)
			dispatch_operation(PA, stack_a, stack_b);
		i++;
	}
}

// 0 2 1
// 1 0 2
// 1 2 0
// 2 0 1
// 2 1 0

void	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	int	top;
	int	middle;
	int	bottom;

	top = peek(stack_a, 0);
	middle = peek(stack_a, 1);
	bottom = peek(stack_a, 2);
	if (top > middle && bottom > middle && top < bottom)
		dispatch_operation(SA, stack_a, stack_b);
	if (top > middle && middle > bottom && top > bottom)
	{
		dispatch_operation(SA, stack_a, stack_b);
		dispatch_operation(RRA, stack_a, stack_b);
	}
	if (top > middle && bottom > middle && top > bottom)
		dispatch_operation(RA, stack_a, stack_b);
	if (top < middle && middle > bottom && top < bottom)
	{
		dispatch_operation(SA, stack_a, stack_b);
		dispatch_operation(RA, stack_a, stack_b);
	}
	if (top < middle && middle > bottom && top > bottom)
		dispatch_operation(RRA, stack_a, stack_b);
}

void	solve(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	if (stack_a->size == 2)
	{
		dispatch_operation(SA, stack_a, stack_b);
		return ;
	}
	if (stack_a->size == 3)
		return (sort_3(stack_a, stack_b));
	// if (stack_a->size <= 5)
	// 	return (sort_5(stack_a, stack_b));
	return (sort_big_stack(stack_a, stack_b));
}
