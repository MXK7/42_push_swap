/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:16:43 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/19 14:52:55 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../push_swap.h"

static void	__ps_sort_3(t_data *stack_a)
{
	if (stack_a->tab[1] < stack_a->tab[0] && stack_a->tab[1] < stack_a->tab[2]
		&& stack_a->tab[2] > stack_a->tab[0])
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	ps_sort_3(t_data *stack_a)
{
	__ps_sort_3(stack_a);
	if (stack_a->tab[1] < stack_a->tab[0] && stack_a->tab[1] < stack_a->tab[2]
		&& stack_a->tab[0] > stack_a->tab[2])
		ra(stack_a);
	else if (stack_a->tab[1] > stack_a->tab[0]
		&& stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[2] < stack_a->tab[0])
		rra(stack_a);
	else if (stack_a->tab[1] < stack_a->tab[0]
		&& stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[2] < stack_a->tab[0])
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if (stack_a->tab[1] > stack_a->tab[0]
		&& stack_a->tab[1] > stack_a->tab[2]
		&& stack_a->tab[2] > stack_a->tab[0])
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	ps_sort_5(t_data *stack_a, t_data *stack_b)
{
	int	size_a;
	int	size_b;

	size_a = stack_a->a;
	size_b = 0;
	while (size_a > 3)
	{
		pb(stack_a, stack_b);
		size_a--;
		size_b++;
	}
	ps_sort_3(stack_a);
	while (size_b > 0)
	{
		pa(stack_a, stack_b);
		size_a++;
		size_b--;
	}
}
