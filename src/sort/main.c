/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:00:34 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/05 19:42:59 by gmasid           ###   ########.fr       */
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

void	solve(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	return (sort_big_stack(stack_a, stack_b));
}
