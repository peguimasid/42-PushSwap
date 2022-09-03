/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:28:22 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/03 16:31:34 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(operation, "SA", 2) == 0)
		return (swap(stack_a));
	if (ft_strncmp(operation, "SB", 2) == 0)
		return (swap(stack_b));
	if (ft_strncmp(operation, "SS", 2) == 0)
		return (swap(stack_a) && swap(stack_b));
	if (ft_strncmp(operation, "RRA", 3) == 0)
		return (reverse_rotate(stack_a));
	if (ft_strncmp(operation, "RRB", 3) == 0)
		return (reverse_rotate(stack_b));
	if (ft_strncmp(operation, "RRR", 3) == 0)
		return (reverse_rotate(stack_a) && reverse_rotate(stack_b));
	if (ft_strncmp(operation, "RA", 2) == 0)
		return (rotate(stack_a));
	if (ft_strncmp(operation, "RB", 2) == 0)
		return (rotate(stack_b));
	if (ft_strncmp(operation, "RR", 2) == 0)
		return (rotate(stack_a) && rotate(stack_b));
	if (ft_strncmp(operation, "PA", 2) == 0)
		return (push_from(stack_b, stack_a));
	if (ft_strncmp(operation, "PB", 2) == 0)
		return (push_from(stack_a, stack_b));
	return (0);
}

int	dispatch_operation(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (execute_operation(operation, stack_a, stack_b))
	{
		ft_printf("%s", operation);
		return (1);
	}
	return (0);
}
