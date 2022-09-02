/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:10:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/02 19:51:21 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		str++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

long	get_val(char *str)
{
	long	result;
	int		i;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
		result = result * 10 + str[i++] - '0';
	if (result > INT_MAX || result < INT_MIN)
		return (2147483648);
	return (result * sign);
}

int	contains_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	fill_array(int *array, int argc, char **argv)
{
	int		i;
	int		j;
	long	val;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if (!is_num(argv[i]))
			return (0);
		val = get_val(argv[i]);
		if (val == 2147483648 || contains_duplicates(array, j))
			return (0);
		array[j] = get_val(argv[i]);
		j++;
		i++;
	}
	return (1);
}

int	*copy_array(int *array, int size)
{
	int	i;
	int	*result;

	i = 0;
	result = malloc(sizeof(int) * size);
	if (!result)
		return (0);
	while (i < size)
	{
		result[i] = array[i];
		i++;
	}
	return (result);
}

int	sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	fill_stack(t_stack *stack, int ac, char **av)
{
	int	i;
	int	j;
	int	*array;
	int	*array_copy;

	array = malloc(sizeof(int) * ac);
	if (!fill_array(array, ac, av))
		return (0);
	array_copy = copy_array(array, ac);
	sort_array(array_copy, ac);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (j < ac)
		{
			if (array[i] == array_copy[j])
			{
				stack->array[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	return (1);
}
