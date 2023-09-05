/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:57:14 by mpoussie          #+#    #+#             */
/*   Updated: 2023/09/05 19:23:51 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ps_sort_5(t_data *stack_a, t_data *stack_b)
{
	while (stack_a->a != 2)
	{
		if (stack_a->tab[0] <= 3)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	if (stack_a->tab[0] == 5)
		sa(stack_a);
	while (stack_b->a != 0)
	{
		if (stack_b->tab[0] == stack_b->a)
			pa(stack_a, stack_b);
		else if (stack_b->tab[1] == stack_b->a)
			rb(stack_b);
		else if (stack_b->tab[2] == stack_b->a)
			rrb(stack_b);
	}
}
