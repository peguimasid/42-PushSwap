/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 18:10:54 by gmasid            #+#    #+#             */
/*   Updated: 2022/09/05 13:43:07 by gmasid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int	*sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;
	int	*array_copy;

	array_copy = copy_array(array, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (array_copy[j] > array_copy[j + 1])
			{
				temp = array_copy[j];
				array_copy[j] = array_copy[j + 1];
				array_copy[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (array_copy);
}

int	fill_stack(t_stack *stack, int ac, char **av)
{
	int	i;
	int	j;
	int	*array;
	int	*array_sorted;

	array = malloc(sizeof(int) * ac);
	if (!fill_array(array, ac, av))
		return (0);
	array_sorted = sort(array, ac);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (j < ac)
		{
			if (array[i] == array_sorted[j])
				push(stack, j);
			j++;
		}
		i++;
	}
	free(array);
	free(array_sorted);
	return (1);
}
