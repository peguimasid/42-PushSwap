/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:04:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/02 14:40:48 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		val;

	if (argc < 2)
		return (throw_error("Plase provide at least one number"));
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	if (!fill_stack(stack_a, argc - 1, argv + 1))
		return (throw_error("You provide a invalid or duplicate number"));
	ft_printf("----------- BEFORE ----------\n");
	ft_printf("STACK A\n");
	print_list(stack_a);
	ft_printf("\n\n");
	ft_printf("STACK B\n");
	print_list(stack_b);
	// ---
	val = peek(stack_a, 1);
	ft_printf("<<<%d>>>\n", val);
	// ---
	ft_printf("\n\n\n----------- AFTER ------------\n");
	ft_printf("STACK A\n");
	print_list(stack_a);
	ft_printf("\n\n");
	ft_printf("STACK B\n");
	print_list(stack_b);
	return (0);
}
