/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:28:22 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/03 16:45:13 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(operation, "sa", 2) == 0)
		return (swap(stack_a));
	if (ft_strncmp(operation, "sb", 2) == 0)
		return (swap(stack_b));
	if (ft_strncmp(operation, "ss", 2) == 0)
		return (swap(stack_a) && swap(stack_b));
	if (ft_strncmp(operation, "rra", 3) == 0)
		return (reverse_rotate(stack_a));
	if (ft_strncmp(operation, "rrb", 3) == 0)
		return (reverse_rotate(stack_b));
	if (ft_strncmp(operation, "rrr", 3) == 0)
		return (reverse_rotate(stack_a) && reverse_rotate(stack_b));
	if (ft_strncmp(operation, "ra", 2) == 0)
		return (rotate(stack_a));
	if (ft_strncmp(operation, "rb", 2) == 0)
		return (rotate(stack_b));
	if (ft_strncmp(operation, "rr", 2) == 0)
		return (rotate(stack_a) && rotate(stack_b));
	if (ft_strncmp(operation, "pa", 2) == 0)
		return (push_from(stack_b, stack_a));
	if (ft_strncmp(operation, "pb", 2) == 0)
		return (push_from(stack_a, stack_b));
	return (0);
}

int	dispatch_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (execute_operation(operation, stack_a, stack_b))
	{
		ft_printf("%s\n", operation);
		return (1);
	}
	return (0);
}
