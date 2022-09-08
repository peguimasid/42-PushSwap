/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:52:43 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/08 15:45:37 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	execute(char *operation, t_stack *stack_a, t_stack *stack_b)
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

void	handle_input(t_stack *stack_a, t_stack *stack_b)
{
	char	*input;

	input = get_next_line(STDIN_FILENO);
	while (input)
	{
		if (!execute(input, stack_a, stack_b))
		{
			throw_error();
			return ;
		}
		free(input);
		input = get_next_line(STDIN_FILENO);
	}
	if (is_empty(stack_b) && is_full(stack_a) && is_sorted(stack_a))
	{
		ft_printf("OK\n");
		return ;
	}
	ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	if (!fill_stack(stack_a, argc - 1, argv + 1))
		return (throw_error());
	handle_input(stack_a, stack_b);
	free_stacks(stack_a, stack_b);
	return (0);
}
