/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:39:42 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/05 09:55:10 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ps_init_nbr(t_data *stack, int argc)
{
	int	i;
	int	x;
	int	count;
	int	*storage;

	storage = malloc(sizeof(int) * (argc - 1));
	i = 0;
	while (i < (argc - 1))
	{
		count = 0;
		x = 0;
		while (x < (argc - 1))
		{
			if (stack->tab[i] > stack->tab[x])
				count++;
			x++;
		}
		storage[i] = count;
		i++;
	}
	ps_init_index(stack, argc, storage);
	free(storage);
}

void	ps_init_index(t_data *stack, int argc, int *storage)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		stack->tab[i] = storage[i];
		i++;
	}
}
