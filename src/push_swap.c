/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:04:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/29 18:47:08 by gmasid           ###   ########.fr       */
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
	stack->index = -1;
	stack->array = (int *)malloc(size * sizeof(int));
	return (stack);
}

int	is_empty(t_stack *stack)
{
	return (stack->index == -1);
}

void	push(t_stack *stack, int item)
{
	stack->array[++stack->index] = item;
	ft_printf("%d pushed to stack\n", item);
}

int	pop(t_stack *stack)
{
	return (stack->array[stack->index--]);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;

	if (argc < 2)
		return (throw_error("Plase provide at least one number"));
	// TODO: Validate if all argv[] are numbers
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
	ft_printf("%d popped from stack\n", pop(stack));
	return (0);
}
