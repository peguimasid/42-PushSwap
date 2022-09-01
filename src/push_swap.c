/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:04:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 11:47:22 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	throw_error(char *error)
{
	ft_printf("\033[0;31m\n");
	ft_printf("Error\n%s\n", error);
	ft_printf("\033[0m");
	return (1);
}

void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d -> ", stack->array[i]);
		i++;
	}
	ft_printf("endIndx = %d", stack->end_index);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (throw_error("Plase provide at least one number"));
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	if (!fill_stack(stack_a, argv + 1))
		return (throw_error("You provide a invalid or duplicate number"));
	ft_printf("----------- BEFORE ----------\n");
	ft_printf("STACK A\n");
	print_list(stack_a);
	ft_printf("\n\n");
	ft_printf("STACK B\n");
	print_list(stack_b);
	// ---
	do_operation("SA", stack_a, stack_b);
	do_operation("SB", stack_a, stack_b);
	// ---
	ft_printf("\n----------- AFTER ------------\n");
	ft_printf("STACK A\n");
	print_list(stack_a);
	ft_printf("\n\n");
	ft_printf("STACK B\n");
	print_list(stack_b);
	return (0);
}
