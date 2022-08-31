/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:04:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/31 18:06:47 by gmasid           ###   ########.fr       */
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

t_stack	*create_stack(unsigned int size)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = size;
	stack->end_index = -1;
	stack->array = (int *)malloc(size * sizeof(int));
	return (stack);
}

int	is_empty(t_stack *stack)
{
	return (stack->end_index == -1);
}

void	push(t_stack *stack, int item)
{
	stack->array[++stack->end_index] = item;
}

int	pop(t_stack *stack)
{
	int	removed_value;

	removed_value = stack->array[stack->end_index];
	stack->array[stack->end_index--] = 0;
	return (removed_value);
}

void	print_list(t_stack *stack)
{
	unsigned int	i;

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
	int		i;

	if (argc < 2)
		return (throw_error("Plase provide at least one number"));
	stack = create_stack(argc - 1);
	i = 1;
	while (argv[i])
	{
		push(stack, ft_atoi(argv[i]));
		i++;
	}
	ft_printf("\n");
	ft_printf("%d popped from stack\n", pop(stack));
	ft_printf("%d popped from stack\n", pop(stack));
	print_list(stack);
	// ft_printf("%d popped from stack\n", pop(stack));
	// ft_printf("%d popped from stack\n", pop(stack));
	return (0);
}
