/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:04:16 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/07 15:37:11 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	throw_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	return (1);
}

// TODO: Remove this function
void	print_list(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("[");
	while (i < stack->size)
	{
		ft_printf("%d", stack->array[i]);
		if (i != stack->size - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("]");
}
