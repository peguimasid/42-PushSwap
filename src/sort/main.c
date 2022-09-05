/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:00:34 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/05 13:05:45 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = -1;
	while (++i < stack->end_index)
		if (stack->array[i] > stack->array[i + 1])
			return (0);
	return (1);
}
