/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:28:22 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/05 19:31:46 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	*get_operation_str(int operation)
{
	if (operation == SA)
		return ("sa");
	if (operation == SB)
		return ("sb");
	if (operation == SS)
		return ("ss");
	if (operation == RRA)
		return ("rra");
	if (operation == RRB)
		return ("rrb");
	if (operation == RRR)
		return ("rrr");
	if (operation == RA)
		return ("ra");
	if (operation == RB)
		return ("rb");
	if (operation == RR)
		return ("rr");
	if (operation == PA)
		return ("pa");
	if (operation == PB)
		return ("pb");
	return ("");
}

int	execute_operation(int operation, t_stack *stack_a, t_stack *stack_b)
{
	if (operation == SA)
		return (swap(stack_a));
	if (operation == SB)
		return (swap(stack_b));
	if (operation == SS)
		return (swap(stack_a) && swap(stack_b));
	if (operation == RRA)
		return (reverse_rotate(stack_a));
	if (operation == RRB)
		return (reverse_rotate(stack_b));
	if (operation == RRR)
		return (reverse_rotate(stack_a) && reverse_rotate(stack_b));
	if (operation == RA)
		return (rotate(stack_a));
	if (operation == RB)
		return (rotate(stack_b));
	if (operation == RR)
		return (rotate(stack_a) && rotate(stack_b));
	if (operation == PA)
		return (push_from(stack_b, stack_a));
	if (operation == PB)
		return (push_from(stack_a, stack_b));
	return (0);
}

// TODO: Make function print just the operation
int	dispatch_operation(int operation, t_stack *stack_a, t_stack *stack_b)
{
	// ft_printf(">> Before:\n");
	// ft_printf("A: ");
	// print_list(stack_a);
	// ft_printf(" | end_index = %d", stack_a->end_index);
	// ft_printf("\n");
	// ft_printf("B: ");
	// print_list(stack_b);
	// ft_printf(" | end_index = %d", stack_b->end_index);
	// ft_printf("\n\n");
	if (execute_operation(operation, stack_a, stack_b))
	{
		ft_printf("%s\n", get_operation_str(operation));
		// ft_printf("\n>> After:\n");
		// ft_printf("A: ");
		// print_list(stack_a);
		// ft_printf("| end_index = %d", stack_a->end_index);
		// ft_printf("\n");
		// ft_printf("B: ");
		// print_list(stack_b);
		// ft_printf("| end_index = %d", stack_b->end_index);
		// ft_printf("\n");
		// ft_printf("\n");
		// ft_printf("----------------------------------------\n");
		return (1);
	}
	return (0);
}
