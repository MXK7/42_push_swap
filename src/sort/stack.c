/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 02:16:41 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/13 02:54:18 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../push_swap.h"

void ps_find_median(t_data *stack_a)
{
	int tmp;

	tmp = stack_a->size - stack_a->small_integer;
	stack_a->small_integer = stack_a->big_integer + (tmp * 1 / 3);
	stack_a->big_integer = stack_a->big_integer + (tmp * 2 / 3);
	if (stack_a->big_integer > stack_a->size - 4)
		stack_a->big_integer = stack_a->size - 4;
}

void ps_sort_a(t_data *stack_a, t_data *stack_b)
{
	while (stack_b->a < stack_a->big_integer && stack_a->a != 3)
	{
		if (stack_a->tab[0] > stack_a->big_integer)
		{
			ra(stack_a);
			stack_a->count_action++;
		}
		else if (stack_a->tab[0] <= stack_a->big_integer)
		{
			pb(stack_a, stack_b);
			stack_a->count_action++;
			if (stack_b->a > 1 && stack_b->tab[0]
				<= stack_a->small_integer && stack_a->a != 3)
			{
				rb(stack_b);
				stack_a->count_action++;
			}
		}
	}
	ps_find_median(stack_a);
}

void	ps_sort_b(t_data *stack_a, t_data *stack_b)
{
	int	tmp;

	while (stack_b->a != 0)
	{
		stack_a->b = 0;
		while (stack_b->tab[stack_a->b] != stack_b->a)
			stack_a->b++;
		tmp = stack_b->a;
		while (tmp != stack_b->tab[0])
		{
			if (stack_b->tab[0] == tmp - 1)
				pa(stack_a, stack_b);
			else if (stack_a->b < (tmp / 2))
				rb(stack_b);
			else
				rrb(stack_b);
		}
		if (stack_b->tab[0] == tmp - 1)
		{
			pa(stack_a, stack_b);
			sa(stack_a);
		}
		else
			pa(stack_a, stack_b);
	}
}
