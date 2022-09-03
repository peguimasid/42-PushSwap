/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:13:18 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/03 16:32:23 by gmasid           ###   ########.fr       */
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
void	free_stack(t_stack *stack);

int		throw_error(char *error);
int		fill_stack(t_stack *stack, int ac, char **av);
int		dispatch_operation(char *operation, t_stack *stack_a, t_stack *stack_b);

int		swap(t_stack *stack);
int		rotate(t_stack *stack);
int		reverse_rotate(t_stack *stack);
int		push_from(t_stack *src_stack, t_stack *dest_stack);

void	push(t_stack *stack, int item);
void	unshift(t_stack *stack, int value);
int		pop(t_stack *stack);
int		shift(t_stack *stack);
int		is_full(t_stack *stack);
int		is_empty(t_stack *stack);
int		peek(t_stack *stack, int i);
int		includes(t_stack *stack, int value);

void	print_list(t_stack *stack);

int		is_num(char *str);
long	get_val(char *str);

#endif
