/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 22:39:42 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 16:32:55 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

static void	ps_init_index(t_data *stack_a, int *storage)
{
	int	i;

	i = 0;
	while (i < stack_a->size - 1)
	{
		stack_a->tab[i] = storage[i];
		i++;
	}
}

void	ps_init_nbr(t_data *stack_a)
{
	int	i;
	int	x;
	int	count;
	int	*storage;

	storage = malloc(sizeof(int) * (stack_a->size - 1));
	i = 0;
	while (i < stack_a->size - 1)
	{
		count = 1;
		x = 0;
		while (x < (stack_a->size - 1))
		{
			if (stack_a->tab[i] > stack_a->tab[x])
				count++;
			x++;
		}
		storage[i] = count;
		i++;
	}
	ps_init_index(stack_a, storage);
	free(storage);
}
