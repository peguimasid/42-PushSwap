/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:13:18 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/01 16:05:40 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int	size;
	int	end_index;
	int	*array;
}		t_stack;

t_stack	*create_stack(unsigned int size);

int		pop(t_stack *stack);
int		is_empty(t_stack *stack);
int		throw_error(char *error);
int		includes(t_stack *stack, int value);
int		fill_stack(t_stack *stack, char **av);
int		do_operation(char *operation, t_stack *stack_a, t_stack *stack_b);

void	push(t_stack *stack, int item);
void	print_list(t_stack *stack);

#endif