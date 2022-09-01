/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:04:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 11:29:25 by gmasid           ###   ########.fr       */
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
	t_stack	*stack;

	if (argc < 2)
		return (throw_error("Plase provide at least one number"));
	stack = create_stack(argc - 1);
	if (!fill_stack(stack, argv + 1))
		return (throw_error("You provide a invalid or duplicate number"));
	pop(stack);
	print_list(stack);
	return (0);
}
