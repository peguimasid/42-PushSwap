/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:13:18 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/08 14:55:55 by gmasid           ###   ########.fr       */
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

enum	e_operations
{
	SA = 11,
	SB = 12,
	SS = 13,
	RA = 21,
	RB = 22,
	RR = 23,
	PA = 31,
	PB = 32,
	RRA = 41,
	RRB = 42,
	RRR = 43
};

t_stack	*create_stack(unsigned int size);
void	free_stacks(t_stack *stack_a, t_stack *stack_b);

int		throw_error(void);
int		fill_stack(t_stack *stack, int ac, char **av);
int		dispatch_operation(int operation, t_stack *stack_a, t_stack *stack_b);

int		is_sorted(t_stack *stack);
void	solve(t_stack *stack_a, t_stack *stack_b);

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

int		is_num(char *str);
long	get_val(char *str);

// TODO: Remove this function
void	print_list(t_stack *stack);

#endif
