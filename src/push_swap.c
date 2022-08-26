/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmasid <gmasid@student.42.rio>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:04:20 by gmasid            #+#    #+#             */
/*   Updated: 2022/08/26 17:14:56 by gmasid           ###   ########.fr       */
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

void	print_nums(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		ft_printf("%s\n", args[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (throw_error("Plase provide at least one number"));
	print_nums(argv + 1);
}
