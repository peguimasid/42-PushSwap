/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:13:18 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/02 13:09:19 by gmasid           ###   ########.fr       */
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

int		throw_error(char *error);
int		fill_stack(t_stack *stack, int ac, char **av);
int		execute_operation(char *operation, t_stack *stack_a, t_stack *stack_b);

void	push(t_stack *stack, int item);
void	unshift(t_stack *stack, int value);
int		pop(t_stack *stack);
int		shift(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
int		includes(t_stack *stack, int value);

void	print_list(t_stack *stack);

#endif
